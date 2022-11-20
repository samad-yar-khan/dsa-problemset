 // for(int i = dp.size()-2;i>=0;i++){
        //     int same = 1;
        //     int incr = 1;
        //     //same
        //     if(vec[i] == vec[i+1]){
        //         same = max(dp[i+1][0] + 1,same);
        //         incr = max(dp[i+1][1] + 1,incr);
        //     }
        //     if(vec[i] == vec[i+1] + 1){
        //         same = max(dp[i+1][1] + 1,same);
        //     }
        //     if(vec[i] + 1== vec[i+1]){
        //         incr = max(dp[i+1][0] + 1,incr);
        //     }
        //     dp[i][0] = same;
        //     dp[i][1] = incr;
        //     ans = max(same,incr);
        // }