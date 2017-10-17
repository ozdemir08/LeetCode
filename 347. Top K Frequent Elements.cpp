////// With heap ///////

class Number{
public:
	int val, count;
	Number(){}
	Number(int v, int c){val = v; count = c;}
};

bool cmp(Number a, Number b){
	return a.count > b.count;
}

class Solution {
private:
	void numberToIntVector(vector<Number>& minHeap, vector<int>& res){
		for(int i=0;!minHeap.empty();i++){
        	Number number = minHeap[0];
        	res.push_back(number.val);

        	pop_heap(minHeap.begin(), minHeap.end(), cmp);
    		minHeap.pop_back();
        }
	}

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countNums;
        for(int i=0;i<nums.size();i++){
        	int num = nums[i];
        	countNums[num] ++;
        }

        vector<Number> minHeap;
        make_heap(minHeap.begin(), minHeap.end(), cmp);

        for(unordered_map<int, int>::iterator it = countNums.begin();it != countNums.end(); it++){
        	int val = it -> first;
        	int count = it -> second;

        	Number num(val, count);
        	minHeap.push_back(num);
        	push_heap(minHeap.begin(), minHeap.end(), cmp);

        	if(minHeap.size() > k){
        		pop_heap(minHeap.begin(), minHeap.end(), cmp);
        		minHeap.pop_back();
        	}
        }

        vector<int> res;
        numberToIntVector(minHeap, res);
        return res;
    }
};

///////// With priority queue /////////

class Solution2{
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> countNums;
        for(int i=0;i<nums.size();i++){
        	int num = nums[i];
        	countNums[num] ++;
        }

        // first for count, second for number
        priority_queue< pair<int,int> > queue; 
        for(unordered_map<int, int>::iterator it = countNums.begin();it != countNums.end(); it++){
        	int val = it -> first;
        	int count = it -> second;

        	pair<int,int> num = make_pair(count, val);
        	queue.push(num);

        	if(queue.size() > k)
        		q.pop();
        }

        vector<int> res;
        for(int i=0;i<k;i++){
        	int val = q.top().second;
        	q.pop();

        	res.push_back(val);
        }
        return res;
	}
};

//////// With Compare function in priority queue ///////////

class Compare
{
public:
    bool operator() (pair<int,int> a, pair<int,int> b)
    {
        return a.first > b.first;
    }
};

class Solution3{
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> countNums;
        for(int i=0;i<nums.size();i++){
        	int num = nums[i];
        	countNums[num] ++;
        }

        // first for count, second for number
        priority_queue<pair<int,int>, std::vector< pair<int,int> >, Compare > q; 
        for(unordered_map<int, int>::iterator it = countNums.begin();it != countNums.end(); it++){
        	int val = it -> first;
        	int count = it -> second;

        	pair<int,int> num = make_pair(count, val);
        	q.push(num);

        	if(q.size() > k)
        		q.pop();
        }

        vector<int> res;
        for(int i=0;i<k;i++){
        	int val = q.top().second;
        	q.pop();

        	res.push_back(val);
        }
        return res;
	}
};