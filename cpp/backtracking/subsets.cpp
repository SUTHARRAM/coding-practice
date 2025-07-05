#include<iostream>
#include<vector>
#include<algorithm>

using namespace std; 

class Subsets {
    private: 
        vector<vector<int>> powerset; 
        vector<vector<int>> powersetd; 
        vector<int> subset; 
        vector<int> nums; 
        int n; 
        int subsetCount; 

    public:
        Subsets(vector<int> inputNums) {
            this->nums = inputNums; 
            this->n = inputNums.size(); 
        } 

        void Subset() {
            backtrack(0); 
            printSubset(powerset); 
        }

        void backtrack(int index) {
            if (index >= n) {
                powerset.push_back(subset); 
                return; 
            }

            subset.push_back(nums[index]); 
            // considor index in subset
            backtrack(index+1); 
            
            // not consider index in subset 
            subset.pop_back(); 

            backtrack(index+1); 
        }

        void printSubset(vector<vector<int>> powerset) {
            cout<<"Subset Cout is : " << powerset.size()<< "\n"; 
            for(auto subset: powerset) {
                cout<<"["; 
                for(auto i:subset) {
                    cout<<i<<" "; 
                }
                cout<<"] \n"; 
            } 
        }
        int GetSubsetCount() {
            subsetCount = powerset.size(); 
            return subsetCount; 
        }
        // input set may contain dupicates but output must not contains duplicate
        void SubsetII() {
            sort(nums.begin(), nums.end()); 
            backtrackduplicate(0); 
            printSubset(powersetd); 
        }

        void backtrackduplicate(int index) {

            if(index > 0 ) {
                while(index<n && nums[index-1] == nums[index]) {
                    index = index + 1; 
                }
            }
            if(index >= n) {
                powersetd.push_back(subset); 
                return; 
            }

            subset.push_back(nums[index]); 

            backtrackduplicate(index+1); 

            subset.pop_back(); 

            backtrackduplicate(index+1); 
            

        }
        // returns all the possible combination with given sum 
        void CombinationSum(int target) {
            bcombsum(0, target); 
            printSubset(powerset); 
        }

        void bcombsum(int index, int target) {
            if (target == 0) {
                powerset.push_back(subset); 
                return; 
            } 

            if (target < 0) {
                return; 
            }

            if(index < n) {
                subset.push_back(nums[index]); 
                bcombsum(index+1, target - nums[index]); 
                subset.pop_back(); 
                bcombsum(index+1, target); 
            } else {
                return; 
            }
        }

        // combination sum II 

        void combinationSumII(int target) {
            sort(nums.begin(), nums.end()); 
            bcombsumII(0, target); 
            printSubset(powerset); 
        }

        void bcombsumII(int index, int target) {
            if(index>0) {
                while(index < n && (nums[index-1] == nums[index])) {
                    index = index + 1; 
                }
            }

                if (target == 0) {
                    powerset.push_back(subset); 
                    return; 
                } 

                if (target < 0 ) {
                    return ; 
                }

                if(index < n) {
                    subset.push_back(nums[index]); 
                    bcombsumII(index+1, target-nums[index]); 
                    subset.pop_back(); 
                    bcombsumII(index+1, target); 
                } else {
                    return; 
                }
        }
}; 


int main() {
    vector<int> nums{1,1,1,2,2, 3, 3, 4, 4, 4,5, 5,6,}; 
    Subsets sobj(nums); 

    //  sobj.Subset(); 

    //  sobj.SubsetII(); 

    //sobj.CombinationSum(10); 

    sobj.combinationSumII(10); 

    return 0; 
}