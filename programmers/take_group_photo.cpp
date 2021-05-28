#include <string>
#include <vector>
#define MEMS 8

using namespace std;

vector<char> members;
vector<string> cond;
int ans;
char list[MEMS];
bool check[101] = { false, }; 

bool checkVality()
{
    int num, obj_pos, sub_pos;
    char obj, sub, exp;
    
    for(string str : cond) {
        obj = str[0];
        sub = str[2];
        exp = str[3];
        num = str[4] - '0';
        
        for(int i = 0; i < MEMS; i++) {
            if(list[i] == obj)
                obj_pos = i;
            if(list[i] == sub)
                sub_pos = i;
        }
        
                // printf("%c[%d] %c[%d] %c\n", obj,obj_pos, sub,sub_pos, exp);
        // printf("%d\n", abs(sub-obj))

        
        
        switch(exp) {
            case '>' :
                if(abs(sub_pos-obj_pos)-1 <= num)
                    return false;
                break;
            case '<' : 
                if(abs(sub_pos-obj_pos)-1 >= num)
                    return false;
                break;
            case '=' :
                if(abs(sub_pos-obj_pos)-1 != num)
                    return false;
                break;
        }

        
    }
    return true;
}

void permu(int depth)
{
    if(depth == MEMS) {
        if(checkVality())
            ans++;
    }   
    
    for(int i = 0; i < MEMS; i++) {
        if(!check[i]) {
            check[i] = true;
            list[depth] = members[i];
            permu(depth+1);
            check[i] = false;
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    members = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    cond = data;
    ans = 0;
    
    permu(0);
    answer = ans;
    return answer;
}