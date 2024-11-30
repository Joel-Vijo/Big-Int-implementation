#include <stdio.h>
void add(char a[],char b[],char sum[]){
    int i1=0;
    while(a[i1]!='\0'){
        i1++;
    }
    int i2=0;
    while(b[i2]!='\0'){
        i2++;
    }
    int c;
    if(i1>i2){
        c=i1;
    }
    else{
        c=i2;
    }
    int i=c;
    char carry='0';
    while(i1>0 && i2>0){
        int x=a[i1-1]-'0'+b[i2-1]-'0'+carry-'0';
        if(x<10){
            sum[i]=a[i1-1]+b[i2-1]-'0'+carry-'0';
            carry='0';
        }
        else{
            sum[i]=a[i1-1]+b[i2-1]-':'+carry-'0';
            carry='1';
        }
        i--;
        i1--;
        i2--;
    }
    if(i1!=0){
        while(i1>0){
            sum[i]=a[i1-1]+carry-'0';
            carry='0';
            i--;
            i1--;
        }
    }
    else if(i2!=0){
        while(i2>0){
            sum[i]=b[i2-1]+carry-'0';
            carry='0';
            i--;
            i2--;
        }
    }

    if(carry=='1'){
        sum[i]='1';
    }
    else{
        sum[i]='0';
    }
    sum[c+1]='\0';
    if(sum[309]!='\0' && sum[0]=='1'){
        sum="Overflow";
    }

}

void subtract(char a[],char b[],char difference[]){
    //printf("%s\n",a);
    //printf("%s\n",b);
    int i1=0;
    while(a[i1]!='\0'){
        i1++;
    }
    int i2=0;
    while(b[i2]!='\0'){
        i2++;
    }
    int c=i1;
    int i=c;
    while(i1>0 && i2>0){
        int x=a[i1-1]-'0'-b[i2-1]+'0';
        if(x>=0){
            difference[i]=a[i1-1]-b[i2-1]+'0';
        }
        else{
            difference[i]=a[i1-1]+':'-'0'-(b[i2-1]-'0');
            if(a[i1-2]=='0'){
                int j=i1-2;
                while(a[j]!='0'){
                    j--;
                }
                a[i1-2]='9';
                a[j]=a[j]-'1'+'0';
            }
            else{
                a[i1-2]=a[i1-2]-'1'+'0';}
        }
        i--;
        i1--;
        i2--;
    }
    if(i1!=0){
        while(i1>0){
            difference[i]=a[i1-1];
            i--;
            i1--;
        }
    }
    else if(i2!=0){
        while(i2>0){
            difference[i]=b[i2-1];
            i--;
            i2--;
        }
    }

    difference[c+1]='\0';

}

void multiply_single(char a[],int c,char b,char product[]){
    if(b=='0'){
        int p=0;
        while(p<=c){
            product[p]='0';
            p++;
        }
        product[p]='\0';
    }
    else{
        int i=1;
        int d=0;
        while(a[d]!='\0'){
            product[d+1]=a[d];
            d++;
        }
        char carry='0';
        while(i<b-'0'){
            int j=c;
            carry='0';
            //printf("%c\n",product[j]);
            while(j>0){
                int x=a[j-1]-'0'+product[j]-'0'+carry-'0';
                //printf("%d\n",x);
                if(x<10){
                    product[j]=a[j-1]+product[j]-'0'+carry-'0';
                    carry='0';
                }
                else{
                    product[j]=a[j-1]+product[j]-':'+carry-'0';
                    carry='1';
                }
                //printf("%c",product[j]);
                j--;
            }
            if(carry=='1'){
                product[j]=product[j]+carry-'0';
            }
            i++;
        }
        
        product[d+1]='\0';
    }
}

void add2(char product[],char sum[]){
    int i1=0;
    while(sum[i1]!='\0'){
        i1++;
    }
    int i=i1;
    int i2=0;
    while(product[i2]!='\0'){
        i2++;
    }
    if(product[1]=='\0'){
        while(i1>0){
            product[i1]=sum[i1-1];
            i1--;
        }
        product[0]='0';
        product[i+1]='\0';
    
    //printf("%s\n",product);
    }
    else{
        char carry='0';
        while(i2>0){
            int x=sum[i1-1]-'0'+product[i2-1]-'0'+carry-'0';
            if(x<10){
                product[i1]=sum[i1-1]+product[i2-1]-'0'+carry-'0';
                carry='0';
            }
            else{
                product[i1]=sum[i1-1]+product[i2-1]-':'+carry-'0';
                carry='1';
            }
            //printf("%c",product[j]);
            i1--;
            i2--;
        }
        if(carry=='1'){
            product[0]='1';
        }
        else{
            product[0]='0';
        }
        product[i+1]='\0';
        //printf("%s\n",product);
    }
}
void multiply(char a[],char b[],char product[]){
    int i=0;
    while(b[i]!='\0'){
        i++;
    }
    i--;
    int c=0;
    while(a[c]!='\0'){
        c++;
    }
    if(i+c>310){
        product="Overflow";
    }
    else{
        int z=0;
        while(i>=0){
            char sum[311]={'0'};
            //printf("%s\n",sum);
            multiply_single(a,c,b[i],sum);
            //printf("%s\n",sum);
            int k=0;
            while(sum[k]!='\0'){
                k++;
            }
            int l=0;
            while(l<z){
                sum[k]='0';
                l++;
                k++;
            }
            sum[k]='\0';
            //printf(" sum %s\n",sum);
            add2(product,sum);
            i--;
            z++;
        }
        if(b[0]=='0' && b[1]=='\0'){
            product[0]='0';
            product[1]='\0';
        }
        if(product[309]!='\0' && product[0]=='1'){
            product="Overflow";
        }
    }
}

int main(){
    char big_int[310];
    printf("Enter the number: ");
    scanf("%s",big_int);
    char big_int2[310];
    printf("Enter the number: ");
    scanf("%s",big_int2);
    char sum[311]={'0'};
    add(big_int2,big_int,sum);
    printf("Sum %s\n",sum);
    char difference[311]={'0'};
    char product[311]={'0'};
    int i=0;
    while(big_int[i]!='\0' && big_int2[i]!='\0'){
        i++;
    }
    if(big_int[i]!='\0'){
        multiply(big_int,big_int2,product);
        subtract(big_int,big_int2,difference);
    }
    else if(big_int2[i]!='\0'){
        multiply(big_int2,big_int,product);
        subtract(big_int,big_int2,difference);
    }
    else{
        i=0;
        while(big_int[i]==big_int2[i]){
            i++;
        }
        if(big_int[i]>big_int2[i]){
            multiply(big_int,big_int2,product);
            subtract(big_int,big_int2,difference);
        }
        else{
            multiply(big_int2,big_int,product);
            subtract(big_int,big_int2,difference);
        }
    }
    printf("Difference %s\n",difference);
    printf("Product %s",product);

}