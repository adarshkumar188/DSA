bool sumGame(char* num) {

    int sum1=0; int sum2=0;

    int q1=0;int q2=0;

    for(int i=0;i<=strlen(num)/2 -1;i++){

        if(num[i]=='?') q1++;
        else sum1+=num[i]-'0';}


    
    for(int i=strlen(num)/2;i<strlen(num);i++){

        if(num[i]=='?') q2++;
        else sum2+=num[i]-'0';}


    if((q1+q2)%2==1) return true;
    
    
    
    int min1=0;int min2=0;
    int max1=0;int max2=0;


    int x=q2>(q1+q2)/2? (q1+q2)/2:q2;

    while(x>=0){
        
        max1=x*9;
        min1=((q1+q2)/2 -x ) * -9;

        max2=(q2-x)*9;
        min2=(q1- (q1+q2)/2 + x)*-9;

        int c=sum1-sum2;

        if(c-max1<min2 || c-min1> max2) return true;
        x--;}

    return false;




    }


    



    




    