// level - medium
// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

// tc : O(n) + O(n * log(n)) + O(n * max(deadline))
// sc : O(n) + O(max(deadline))

class Solution {
  public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        // code here
        int mDead = 0;
        for(int i=0;i<deadline.size();i++) {
            mDead = max(mDead, deadline[i]);
        }

        vector<pair<int, pair<int, int>>> jobs;
        for(int i=0;i<id.size();i++) {
            jobs.push_back(make_pair(id[i], make_pair(deadline[i], profit[i])));
        }
        
        sort(jobs.begin(), jobs.end(), [](const auto& a, const auto& b) {
            return a.second.second > b.second.second;
        });
        
        vector<int> days(mDead+1, -1);
        
        int jobCount = 0;
        int mProfit = 0;
        
        for(int i=0;i<jobs.size();i++) {
            int id = jobs[i].first;
            int dl = jobs[i].second.first;
            int pro = jobs[i].second.second;
            
            if(days[dl] == -1) {
                days[dl] = id;
                jobCount += 1;
                mProfit += pro;
            }
            else {
                while(--dl) {
                    if(days[dl] == -1) {
                        days[dl] = id;
                        jobCount += 1;
                        mProfit += pro;
                        
                        break;
                    }
                }
            }
        }
        
        return {jobCount,mProfit};
    }
};