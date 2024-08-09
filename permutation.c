char* getPermutation(int n, int k) {
    char* s = malloc(n + 1);
    s[n] = '\0';
    bool present[n];
    for(int i=0; i<n; i++){
        present[i]=false;
    }
    int remainder = k-1;
    int fact[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    for(int i=0; i<n; i++){
        int jump = remainder/fact[n-i-1];
        remainder=remainder%fact[n-i-1];
        int j=0;
        printf("%d %d\n", jump, remainder);
        while(true){
            if(!present[j]){
                if(jump==0){
                    break;
                }
                jump--;
            }
            j++;
        }
        present[j]=true;
        s[i]=j+49;
    }
    return s;
} 
