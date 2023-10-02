#include <iostream>//20216010_Ahmed maher,20216064_Essam alaa
#include <climits>
using namespace std;
int knapSack(int v[], int w[], int n, int W) {
   if (W < 0)
      return INT_MIN;
   if (n < 0 || W == 0)
      return 0;
   int in = v[n] + knapSack(v, w, n - 1, W - w[n]);
   int ex = knapSack(v, w, n - 1, W);
   return max (in, ex);
}
int main() {
    int capacity;
    int x;
    cout << "Enter number of items = ";
    cin >> x;
    const int c = x;
    int valueArry[c];
    for (size_t i = 0; i < c; i++) {
        cout << "Please,Enter element of value array = ";
        cin >> valueArry[i];
    }
    int weightArry[c];
    for (size_t i = 0; i < c; i++) {
        cout << "Please,Enter element of weight array = ";
        cin >> weightArry[i];
    }
    cout << "Please,Enter the maximum weight = ";
    cin >> capacity;
    int n = sizeof(valueArry) / sizeof(valueArry[0]);
    cout << "Knapsack value is " << knapSack(valueArry, weightArry, n - 1, capacity);
    return 0;
}