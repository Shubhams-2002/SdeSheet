//left and right max in O(n) and O(1) as we ensure that there exists a floor 
//of height greater or equal to other side and hence we can directly add leftmax-height[i] 
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0, right=n-1;
        int left_max=0, right_max=0;
        int ans=0;
        while(left<=right) {
            if(height[left] <= height[right]) {
                if(height[left] > left_max) left_max = height[left];
                ans += left_max - height[left];
                left++;
            }
            else {
                if(height[right] > right_max) right_max = height[right];
                ans += right_max - height[right];
                right--;
            }
        }
        return ans;
    }
};

//finding peak value and traversing from 0 to peak and directly calculate area
// and similarly traverse from n-1 to peak and directly calculate area
#include <climits>
long getTrappedWater(long *arr, int n){

    //Reference point.
    int peak = 0;

    // Result.
    long ans = 0L;


    if (n == 0) {
        return 0L;
    }

    long peakVal = arr[0];

    // Moving left to right.
    for (int i = 0; i < n; i++) {
        if (arr[i] >= peakVal) {
            peak = i;
            peakVal = arr[i];
        }
    }

    // Initialising a min value.
    long maxSoFar = LONG_MIN;
    long countSubmerged = 0L;
    long submergedArea = 0L;

    // Traversing over a peak.
    for (int i = 0; i <= peak; i++) {
        if (arr[i] >= maxSoFar) {

            // Calculation.
            ans += (countSubmerged * maxSoFar - submergedArea);
            maxSoFar = arr[i];
            countSubmerged = 0L;
            submergedArea = 0L;
        }

        else {
            submergedArea += arr[i];
            countSubmerged++;
        }
    }

    // Initialising a min value.
    maxSoFar = LONG_MIN;
    countSubmerged = 0L;
    submergedArea = 0L;

    // Moving right to left.
    for (int i = n - 1; i >= peak; i--) {
        if (arr[i] >= maxSoFar) {

            // Calculation.
            ans += (countSubmerged * maxSoFar - submergedArea);
            maxSoFar = arr[i];
            countSubmerged = 0L;
            submergedArea = 0L;
        }

        else {
            submergedArea += arr[i];
            countSubmerged++;
        }
    }

    return ans;
}

