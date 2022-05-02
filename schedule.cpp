//스케줄 짜는 프로그램입니다

#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<int, string> day;
class Alba{
private :
    char* name;
    int canDay[7];
public :
    Alba(){
        for(int i=0; i<7; i++)
            canDay[i] = 1;
    }

    void setName(char* name_){
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
    char* getName(){
        return name;
    }
    bool checkOkay(int d){
        if(canDay[d] == 1) return true;
        else return false;
    }
};

void intro();
void howManyNeed(int hmd[7]);
void setAlba(vector<Alba> v);
void checkAlba(vector<Alba> v);

int main(){
    day[0] = "일"; day[1] = "월"; day[2] = "화"; day[3] = "수"; day[4] = "목"; day[5] = "금"; day[6] = "토";

    int SMTWTFS[7];
    vector<Alba> albas;

    // intro();
    // howManyNeed(SMTWTFS);
    setAlba(albas);
    // checkAlba(albas);
}

void intro(){
    cout << "스케줄을 짜보자." << endl << endl;
}
void howManyNeed(int hmd[7]){
    cout << "월화수목금토일 몇명씩?" << endl;
    for(int i=0; i<7; i++){
        cin >> hmd[i%7];
    }
    cout << endl;
}
void setAlba(vector<Alba> v){
    int totAlba;
    char* name;

    cout << "알바 총 몇명? : ";
    cin >> totAlba;
    for(int i=0; i<totAlba; i++){
        cout << endl;
        Alba a;
        cout << i+1 << "번째 알바 이름 : ";
        cin >> name;
        a.setName(name);
        cout << i+1 << "번째 setName 완료" << endl;
        a.setCanDay();
        cout << i+1 << "번째 setCanDay 완료" << endl;
        v.push_back(a);
        cout << i+1 << "번째 vector pushback 완료" << endl;
    }
    cout << "입력 끝";
}
void checkAlba(vector<Alba> v){
    for(int i=0; i<v.size(); i++){
        cout << "노예" << i+1 << " " << v[i].getName() << " 가능한 날 : ";
        for(int j=0; j<7; j++)
            if(v[i].checkOkay(i))
                cout << day[i] << " ";
        cout << endl;
    }
}