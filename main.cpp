#include <bits/stdc++.h>
#include<unistd.h>
using namespace std;
void FCFS(vector<int> &arr, int head)
{   int size=arr.size();
    int seek_count = 0;
    int distance, cur_track;
 
    for (int i = 0; i < size; i++) {
        cur_track = arr[i];
 
        // calculate absolute distance
        distance = abs(cur_track - head);
 
        // increase the total count
        seek_count += distance;
 
        // accessed track is now new head
        head = cur_track;
    }
 
    cout << "Total number of seek operations = "
         << seek_count << endl;
 
    // Seek sequence would be the same
    // as request array sequence
    cout << "Seek Sequence is" << endl;
 
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}
void calculatedifference(vector<int> &arr, int head,
int diff[][2], int n)
{
for(int i = 0; i < n; i++)
{
diff[i][0] = abs(head - arr[i]);
}
}

// Find unaccessed track which is
// at minimum distance from head
int findMIN(int diff[][2], int n)
{
int index = -1;
int minimum = 1e9;

for(int i = 0; i < n; i++)
{
if (!diff[i][1] && minimum > diff[i][0])
{
minimum = diff[i][0];
index = i;
}
}
return index;
}

void ShortestSeekTimeFirst(vector<int> &arr,
int head)
{
    int n=arr.size();
if (n == 0)
{
return;
}

// Create array of objects of class node
int diff[n][2] = { { 0, 0 } };

// Count total number of seek operation
int seekcount = 0;

// Stores sequence in which disk access is done
int seeksequence[n + 1] = {0};

for(int i = 0; i < n; i++)
{
seeksequence[i] = head;
calculatedifference(arr, head, diff, n);
int index = findMIN(diff, n);
diff[index][1] = 1;

// Increase the total count
seekcount += diff[index][0];

// Accessed track is now new head
head = arr[index];
}
seeksequence[n] = head;

cout << "Total number of seek operations = "
<< seekcount << endl;
cout << "Seek sequence is : " << "\n";

// Print the sequence
for(int i = 0; i <= n; i++)
{
cout << seeksequence[i] << "\n";
}
}

void CSCAN(vector<int> &arr, int head,int disk_size)
{
    int size=arr.size();
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;
 
    // appending end values
    // which has to be visited
    // before reversing the direction
    left.push_back(0);
    right.push_back(disk_size - 1);
 
    // tracks on the left of the
    // head will be serviced when
    // once the head comes back
    // to the beginning (left end).
    for (int i = 0; i < size; i++) {
        if (arr[i] < head)
            left.push_back(arr[i]);
        if (arr[i] > head)
            right.push_back(arr[i]);
    }
 
    // sorting left and right vectors
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
 
    // first service the requests
    // on the right side of the
    // head.
    for (int i = 0; i < right.size(); i++) {
        cur_track = right[i];
        // appending current track to seek sequence
        seek_sequence.push_back(cur_track);
 
        // calculate absolute distance
        distance = abs(cur_track - head);
 
        // increase the total count
        seek_count += distance;
 
        // accessed track is now new head
        head = cur_track;
    }
 
    // once reached the right end
    // jump to the beginning.
    head = 0;
 
    // adding seek count for head returning from 199 to 0
    seek_count += (disk_size - 1);
 
    // Now service the requests again
    // which are left.
    for (int i = 0; i < left.size(); i++) {
        cur_track = left[i];
 
        // appending current track to seek sequence
        seek_sequence.push_back(cur_track);
 
        // calculate absolute distance
        distance = abs(cur_track - head);
 
        // increase the total count
        seek_count += distance;
 
        // accessed track is now the new head
        head = cur_track;
    }
 
    cout << "Total number of seek operations = "
         << seek_count << endl;
 
    cout << "Seek Sequence is" << endl;
 
    for (int i = 0; i < seek_sequence.size(); i++) {
        cout << seek_sequence[i] << endl;
    }
}
 
void SCAN(vector<int> &arr, int head,int disk_size)
{    
     string direction="left";
    int size=arr.size();
int seek_count = 0;
int distance, cur_track;
vector<int> left, right;
vector<int> seek_sequence;

// appending end values
// which has to be visited
// before reversing the direction
if (direction == "left")
left.push_back(0);
else if (direction == "right")
right.push_back(disk_size - 1);

for (int i = 0; i < size; i++) {
if (arr[i] < head)
left.push_back(arr[i]);
if (arr[i] > head)
right.push_back(arr[i]);
}

// sorting left and right vectors
sort(left.begin(), left.end());
sort(right.begin(), right.end());

// run the while loop two times.
// one by one scanning right
// and left of the head
int run = 2;
while (run--) {
if (direction == "left") {
for (int i = left.size() - 1; i >= 0; i--) {
cur_track = left[i];

// appending current track to seek sequence
seek_sequence.push_back(cur_track);

// calculate absolute distance
distance = abs(cur_track - head);

// increase the total count
seek_count += distance;

// accessed track is now the new head
head = cur_track;
}
direction = "right";
}
else if (direction == "right") {
for (int i = 0; i < right.size(); i++) {
cur_track = right[i];
// appending current track to seek sequence
seek_sequence.push_back(cur_track);

// calculate absolute distance
distance = abs(cur_track - head);

// increase the total count
seek_count += distance;

// accessed track is now new head
head = cur_track;
}
direction = "left";
}
}

cout << "Total number of seek operations = "
<< seek_count << endl;

cout << "Seek Sequence is" << endl;

for (int i = 0; i < seek_sequence.size(); i++) {
cout << seek_sequence[i] << endl;
}
}

int main() {
    // Write C++ code here
    int disk_size;
   
    int n;
    cout<<"Enter number of requests";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter request entries";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int head;
    cout<<"Enter current position of pointer"<<endl;
    cin>>head;
    sleep(5);
    cout<<"Enter your choice corresponding to following algorithms"<<endl;
    cout<<"1. First in First out"<<endl;
    cout<<"2. Shortest Seek Time First"<<endl;
    cout<<"3. SCAN algorithm"<<endl;
    cout<<"4. CSCAN algorithm"<<endl;
    int choice;
    cin>>choice;
   
    switch(choice){
        case 1:
        FCFS(arr,head);
        break;
        case 2:
        ShortestSeekTimeFirst(arr,head);
        break;
        case 3:
        cout<<"Enter the disk size";
         cin>>disk_size;
        SCAN(arr,head,disk_size);
        break;
        case 4:
        cout<<"Enter the disk size";
        cin>>disk_size;
        CSCAN(arr,head,disk_size);
        break;
        default:
        cout<<"INVALID INPUT";
        break;
    }

   
}