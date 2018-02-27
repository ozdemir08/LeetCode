class Solution {
public:
    int rotatedDigits(int N) {
        int result = 0;
        vector<int> unpermittedNumbers = {3, 4, 7};
        vector<int> rotationNumbers = {2, 5, 6, 9};

        for(int i=1;i<=N;i++){
            int num = i;
            int rotations = 0, unpermitteds = 0;
            while(num){
                int digit = num % 10;
                num /= 10;

                if(find(unpermittedNumbers.begin(), unpermittedNumbers.end(), digit) != unpermittedNumbers.end()){
                	unpermitteds++;
                	break;
                }
                if(find(rotationNumbers.begin(), rotationNumbers.end(), digit) != rotationNumbers.end())
                	rotations++;
            }
            if(!unpermitteds && rotations > 0)
            	result++;
        }
        return result;
    }
};