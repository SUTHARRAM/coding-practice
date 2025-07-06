#include<iostream>
#include<vector>


using namespace std; 


class Permutations {
    private: 
        vector<vector<int>> solutions; 

        vector<int> temparr; 

        vector<int> nums; 

        int N; 

    public: 
        Permutations(vector<int> input) {
            this->nums = input; 
            this->N = input.size(); 
        }


        void GetAllPermutations() {
            calculatePer();
            printAllPermutations(); 
        }

        bool CheckValueCanBeUsed(int val) {
            for(auto i: temparr) {
                if (i==val) {
                    return false; 
                }
            }
            return true; 
        }

        void printAllPermutations() {
            cout<<"Possible Solutions : "<< solutions.size()<<endl; 
            cout<<"[ "<<endl; 
            for(auto sol:solutions) {
                cout<<"[ "; 
                for(auto val: sol) {
                    cout<<val<<" "; 
                }
                cout<<"] "<<endl; 
            }
            cout<<"]"<<endl; 
        }

        void calculatePer() {
            if (temparr.size() == N) {
                solutions.push_back(temparr); 
                return; 
            }

            for(int i=0 ; i<N; i++) {
               if (CheckValueCanBeUsed(nums[i])) {
                // use that value
                temparr.push_back(nums[i]); 
                calculatePer(); 
                // not use that value
                temparr.pop_back(); 
               }
            }
        }

}; 


int main() {

    Permutations obj({1,2,3}); 

    obj.GetAllPermutations(); 

    return 0; 
}