//Saatvik Srivastava
//SRM Institute of Science & Technology
class trapping {
    public int trap(int[] height) {
        int n = height.length;
    int left[] = new int[n];
    int right[] = new int[n];
         left[0] = height[0];    
        for(int i =1;i< n;i++){
            left[i] = Math.max(left[i-1], height[i]);
        }

right[n-1] = height[n-1];
        for(int j =n-2;j>=0;j--){
            right[j] = Math.max(right[j+1],height[j]);
        }
        int res = 0;
        for(int k=0;k<n;k++){
            res = res + (Math.min(left[k],right[k])- height[k]);
        }
        return res;
    }
}
