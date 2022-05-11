//스케줄 짜는 프로그램입니다

#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<int, string> day;
class Alba{
private :
    string name;
    int canDay[7];
    int stack;
    int rsltDay[7];
public :
    Alba(){
        for(int i=0; i<7; i++){
            canDay[i] = 1;
            rsltDay[i] = 0;
        }
        stack = 0;
    }

    void setName(string name_){
        this->name = name_;
    }
    void setCanDay(){
        int d;
        cout << name << "의 불가능한 날 입력 (월:1, 화:2, ..., 일:7 | 더이상 없으면 0 입력) : " << endl;
        cin >> d;
        while(d){
            canDay[d%7] = 0;
            cin >> d;
        }
    }
    string getName(){return name;}
    bool checkOkay(int d){
        if(canDay[d] == 1) return true;
        else return false;
    }
    void setStack(int stack_){this->stack = stack_;}
    int getStack(){return stack;}
    void setRsltDay(int d){
        rsltDay[d] = 1;
        stack--;
    }
    void printRslt(){
        cout << name << " 출근 요일 : ";
        for(int i=0; i<7; i++)
            if(rsltDay[(i+1)%7]==1)
                cout << day[(i+1)] << " ";
            
        cout << endl;
    }
};

void intro();
void howManyNeed(int hmd[7]);
vector<Alba> setAlba(vector<Alba> v);
void checkAlba(vector<Alba> v);
void setHMD(vector<Alba> v, int d[7]);
void noOtherWay(int week[7], vector<Alba> v);
void makeComb(int week[7], vector<Alba> v, int i);


int main(){
    day[0] = "일"; day[1] = "월"; day[2] = "화"; day[3] = "수"; day[4] = "목"; day[5] = "금"; day[6] = "토";
    int howMany;
    int SMTWTFS[7];
    vector<Alba> albas;


    intro();
    howManyNeed(SMTWTFS);
    albas = setAlba(albas);
    checkAlba(albas);
    setHMD(albas, SMTWTFS);
    noOtherWay(SMTWTFS, albas);
    for(int i=0; i<albas.size(); i++)
        albas[i].printRslt();
}

void intro(){
    cout << "스케줄을 짜보자." << endl << endl;
}
void howManyNeed(int hmd[7]){
    cout << "월화수목금토일 몇명씩?" << endl;
    for(int i=0; i<7; i++){
        cin >> hmd[(i+1)%7];
    }
    cout << endl;
}
vector<Alba> setAlba(vector<Alba> v){
    int totAlba;
    string name;

    cout << "알바 총 몇명? : ";
    cin >> totAlba;
    for(int i=0; i<totAlba; i++){
        cout << endl;
        Alba a;
        cout << i+1 << "번째 알바 이름 : ";
        cin >> name;
        a.setName(name);
        a.setCanDay();
        v.push_back(a);
    }
    cout << "입력 끝" << endl << endl;
    return v;
}
void checkAlba(vector<Alba> v){
    for(int i=0; i<v.size(); i++){
        cout << "노예" << i+1 << " " << v[i].getName() << " 가능한 날 : ";
        for(int j=0; j<7; j++)
            if(v[i].checkOkay((j+1)%7))
                cout << day[(j+1)%7] << " ";
        cout << endl;
    }
    cout << endl;
}
void setHMD(vector<Alba> v, int d[7]){
    int totDays = 0;
    int sacrifice;
    int howMany = v.size();

    for(int i=0; i<7; i++)
        totDays += d[i];
    if(totDays%howMany == 0){
        for(int i=0; i<howMany; i++)
            v[i].setStack(totDays/howMany);
    }
    else{
        sacrifice = totDays%howMany;
        cout << sacrifice << "명은 하루를 더 희생해야 합니다... 누가 할래? " << endl;
        for(int i=0; i<howMany; i++)
            cout << i+1 << " " << v[i].getName() << endl;
        for(int i=0; i<sacrifice; i++){ //하루 더 할 사람들
            int who;
            cin >> who;
            v[who-1].setStack(totDays/howMany+1);
        }
        for(int i=0; i<howMany; i++) //하루 덜 할 사람들
            if(v[i].getStack()==0)
                v[i].setStack(totDays/howMany);
    }
    cout << endl;
    for(int i=0; i<howMany; i++)
        cout << v[i].getName() << " " << v[i].getStack() << "일 출근" << endl;
    cout << endl;
}
void noOtherWay(int week[7], vector<Alba> v){
    int albaTot;
    for(int i=0; i<7; i++){
        albaTot = 0;
        for(int j=0; j<v.size(); j++)
            if(v[j].checkOkay(i))
                albaTot++;
        if(albaTot==week[i]){
            for(int j=0; j<v.size(); j++)
                if(v[j].checkOkay(i)){
                    v[j].setRsltDay(i);
                }
        }
    }
}
void makeComb(int week[7], vector<Alba> v, int i){
    
}