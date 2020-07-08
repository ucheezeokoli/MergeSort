#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int Merge(vector<int>& unsorted, int start, int half, int end){
    // cout << "check: " << start << " "<<half << " "<< (half + 1) << " " << end <<endl;
    // int i,k = start;
    // int j   = secondHalf;
    
    vector<int>sorted((end - start) + 1);

    int i = start;
    int j = (half + 1);
    int k = 0;

    while (i <= half && j <= end){
        if(unsorted.at(i) <= unsorted.at(j)){
            sorted.at(k) = unsorted.at(i);
            k++;
            i++;
        }
        else{
            sorted.at(k) = unsorted.at(j);
            k++;
            j++;
        }
    }

    while (i <= half) {
        sorted.at(k) = unsorted.at(i);
        k++;
        i++;
    }

    while (j <= end) {
        sorted.at(k) = unsorted.at(j);
        k++;
        j++;
    }

    for (i = start; i <= end; i++){
        unsorted.at(i) = sorted.at(i-start);
    }
    
    // for (i = 0; i < unsorted.size(); i++){
    //     cout<< unsorted.at(i)<< ";";
    // }
    // cout<<endl;

    // int i, k, j;
    // vector<int> left(firstHalf - start + 1);
    // vector<int> right(end - firstHalf);

    // for (i = 0; i < left.size(); i++){
    //     left.at(i) = unsorted.at(start + i);
    // }
    // for (j = 0; j < right.size(); j++){
    //     right.at(j) = unsorted.at(secondHalf + j);
    // }

    // i, j= 0;
    // k = start;

    // while (i < left.size() && j < right.size()){
    //     if (left.at(i) <= right.at(j)){
    //         unsorted.at(k) = left.at(i);
    //         i++;
    //     }
    //     else{
    //         unsorted.at(k) = right.at(j);
    //         j++;
    //     }
    //     k++;
    // }

    // while (i < left.size()){
    //     unsorted.at(k) = left.at(i);
    //     i++;
    //     k++;
    // }

    // while (j < right.size()){
    //     unsorted.at(k) = right.at(j);
    //     j++;
    //     k++;
    // }





    // while (i <= firstHalf && j <= end){
    //     if (unsorted.at(i) <= unsorted.at(j)){
    //         sorted.at(k) = unsorted.at(i);
    //         i++; 
    //     }
    //     else {
    //          sorted.at(k) = unsorted.at(j);
    //          j++;
    //     }
    //     k++;
    // }

    // if (i > firstHalf){
    //     while (j <= end){
    //         sorted.at(k) = unsorted.at(j);
    //         j++;
    //         k++;
    //     }
    // }
    // else {
    //     while (i <= firstHalf){
    //         sorted.at(k) = unsorted.at(i);
    //         i++;
    //         k++;
    //     }
    // }
    // for (k = start; k <= end; k++){
    //     unsorted.at(k) = sorted.at(k);
    // }
}

int MergeSort (vector<int>& unsorted, int start, int end){

    if (start < end){
        int half = (start + end) / 2;
        // int firstHalf = half;
        // int secondHalf = (firstHalf + 1);

        MergeSort(unsorted, start, half);
        MergeSort(unsorted, (half + 1), end);
        Merge(unsorted, start, half, end);

    }
    // cout << "sorted: ";
    // int i;
    // for (i = 0; i < sorted.size(); i++){
    //     cout << sorted.at(i) << ";";
    // }
    // cout <<endl;
}

int main()
{
    int start = 0;
    int size;
    cin >> size;

    vector<int> unsorted(size); // DECLARE VECTOR WITH SIZE FROM INPUT
    vector<int> done(size);

    // FILL VECTOR W/ UNSORTED VALUES
    int i;
    for (i = 0; i < size; i++)
    {
        cin >> unsorted.at(i);
    }

    int end = (size - 1);

    MergeSort(unsorted, start, end);

    // cout << "sorted: ";

    for (i = 0; i < unsorted.size(); i++){
        cout << unsorted.at(i) << ";";
    }
}
