#include <iostream>
#define INF 999999
#define size 25
using namespace std;

int N, gate[size] = {}, human[size] = {}, arr[size] = {};
int hoan_vi[size] = {}, check[size] = {};
int res;

void backtrack(int arr[], int index) {
    //if(index > 3) return;
    int n = hoan_vi[index];
    // n = index;
    int pos = gate[n];
    int num = human[n];
    int i = 0;
    while(num > 0 && i < N) {
        if(i == 0 && arr[pos] == 0) {
            arr[pos] = 1;
            num--;
        } else {
            int left = pos - i;
            int right = pos + i;
            if(left >= 1 && right <= N && arr[left] == 0 && arr[right] == 0 && num == 1) {
                int arr_temp[size] = {};
                for(int i = 1; i <= N; i++) {
                    arr_temp[i] = arr[i];
                }
                num--;
                arr_temp[left] = pos - left + 1;
                backtrack(arr_temp, index + 1);
                arr[right] = right - pos + 1;
                backtrack(arr, index + 1); //comment or not comment
            }
            if(left >= 1 && arr[left] == 0 && num > 0) {
                arr[left] = pos - left + 1;
                num--;
            }
            if(right <= N && arr[right] == 0 && num > 0) {
                arr[right] = right - pos + 1;
                num--;
            }
        }
        i++;
    }
    if(index >= 3) {
        int temp = 0;
        for(int i = 1; i <= N; i++) {
            temp += arr[i];
        }
        if(res > temp) res = temp;
    } else
        backtrack(arr, index + 1);

}
void sinh_(int index) {
    if(index > 3) {
        for(int i = 1; i <= N; i++) 
            arr[i] = 0;
        backtrack(arr, 1);
        return;
    }
    for(int i = 1; i <= 3; i++) {
        if(check[i] == 0) {
            check[i] = 1;
            hoan_vi[index] = i;
            sinh_(index + 1);
            check[i] = 0;
        }
    }
}
int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t = 1;
    cin >> t;
    while(t--){

        cin >> N;
        for(int i = 1; i <= 3; i++) cin >> gate[i];
        for(int i = 1; i <= 3; i++) cin >> human[i];
        //algorithmns
        res = INF;
        sinh_(1);
        cout << res << endl;
        //reset
        for(int i = 1; i < size; i++) {
            gate[i] = human[i] = 0;
            arr[i] = hoan_vi[i] = check[i] = 0;
        }
    }
    return 0;
}
