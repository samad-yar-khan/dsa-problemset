    int numberOfSteps(int num) {
        int c =0;
        while(num!=0){
            if(num==1 || ((num&1)==0)){
               c++;
            }else{
                c+=2;
            }
            num=num>>1;
        }
        return c;
    }