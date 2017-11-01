class Solution {
private:
	// sort acc. to smaller width and greater height first.
	static bool cmp(pair<int, int>& a, pair<int, int>& b){
		if(a.first != b.first)
			return a.first < b.first;
		return a.second > b.second;
	}
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    	int N = envelopes.size();

    	// sort according to weight and size of 
    	// longest increasing subsequence of heights is result
    	sort(envelopes.begin(), envelopes.end(), cmp);
    	vector<int> lis(N, 0);
    	int size = 0;

    	// lis
    	for(int i=0;i<N;i++){
            int h = envelopes[i].second;
            
            //binary search for position
            int l = 0, r = size - 1;
    		while(l <= r){
    			int m = (l+r) / 2;
    			if(lis[m] < h)
    				l = m+1;
    			else
    				r = m-1;
    		}
            
            // l is the position of height
    		lis[l] = envelopes[i].second;
    		if(l == size)
    			size++;
    	}
    	return size;
    }
};