int Permutationsolver(char *s, int n, int k, bool * present, int count, int gen){
    for(int i=0; i<n; i++){
        if(!present[i]){
            char c = i+49;
            present[i]=true;
            if(gen!=n-1){
                count = Permutationsolver(s, n, k, present, count, gen+1);
                if(count==k){
                    s[gen]=c;
                    return count;
                }
            }
            else{
                count++;
                if(count==k){
                    s[gen]=c;
                    return count;
                }
            }
            present[i]=false;
        }
    }
    return count;
}
char* getPermutation(int n, int k) {
    char* s = malloc(n + 1);
    s[n] = '\0';
    bool present[n];
    for(int i=0; i<n; i++){
        present[i]=false;
    }
    char count = Permutationsolver(s, n, k, present, 0, 0);
    return s;
}
