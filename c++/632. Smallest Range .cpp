
class Number {
public:
	int val;
	int index;
	int row;
    
    Number(int v, int i, int r){
        val = v;
        index = i;
        row = r;
    }
};

class Compare{
public:
    bool operator() (Number a, Number b){
        return a.val > b.val;
    }  
};

class Solution {
public:
    vector<int> smallestRange(vector< vector<int> >& nums) {
        int n = nums.size();
        priority_queue<Number, vector<Number>, Compare> queue;

        int minRange = INT_MAX, minRangeBegin, minRangeEnd;
        int mn = INT_MAX, mx = INT_MIN;

        // add first elements from each row to queue.
        for(int i=0;i<n;i++){
        	int val = nums[i][0];
        	mn = min(mn, val);
        	mx = max(mx, val);
        	Number num(val, 0, i);
        	queue.push(num);
        }

        while(!queue.empty()){
        	// get smallest from queue
        	Number num = queue.top();
        	queue.pop();

        	mn = num.val;
            
            // check range
            if(mx - mn < minRange){
        		minRange = mx - mn;
        		minRangeBegin = mn;
        		minRangeEnd = mx;
        	}
            
        	// finish if min has reached end
        	if(num.index == nums[num.row].size()-1)
        		break;

        	// add next number
        	int index = num.index + 1;
        	int row = num.row;
        	int val = nums[row][index];

        	mx = max(mx, val);

        	Number next(val, index, row);
        	queue.push(next);
        }
        // add result
        vector<int> res;
        res.push_back(minRangeBegin);
        res.push_back(minRangeEnd);
        return res;
    }
};