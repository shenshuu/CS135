#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

bool header(string line){
    if(line.length()<30 && isupper(line[0]) && isupper(line[1])){
        return true;
    }
    else{
        return false;
    }
}

bool empty_line(string line){
    if(line.length()==0|| !isalpha(line[0]) || line.empty() || line[0]=='\n'){
        return true;
    }
    else{
        return false;
    }
}

string amount_space(int numb){
    string space;
    for(int i = 0; i < numb-1 ;i++){
        space+=" ";
    }
    return space;
}

string amount_space_center(int length, int max_width){
    int numb;
    string space;
    if(length%2!=0){
        numb = (max_width - length)/2+1;
    }
    else{
        numb = (max_width - length)/2;
    }
    for(int i = 0; i < numb-1 ;i++){
        space+=" ";
    }
    return space;
}

int width(string line){
    int numb;
    numb=stoi(line);
    return numb;
}
int main(){
    string word,firstline,line,title,temp_str="",junk,header_dir,body_dir;
    string outfile_name,infile_name;
    int cur_width=0,max_width,set1,set2;
    cout<<"Enter the input filename: ";
    cin>> infile_name;
    int x=0,y=0;
    
    ifstream infile;
    infile.open(infile_name);
    
    
    getline(infile,firstline);
    string temp_word;
    int sub1=0;
    for(int i=0;i<firstline.length();i++){
        if(firstline[i]!=';'){
            temp_word+=firstline[i];
        }
        else if(sub1==0&&firstline[i]==';'){
            max_width = stoi(temp_word);
            temp_word="";
            sub1++;
        }
        else if(sub1==1&&firstline[i]==';'){
            body_dir=temp_word;
            temp_word="";
            sub1++;
        }
        else if(sub1==2&&firstline[i]==';'){
            header_dir=temp_word;
            temp_word="";
            sub1++;
        }
        else if(sub1==3&&firstline[i]==';'){
            outfile_name=temp_word;
            temp_word="";
            sub1++;
        }
    }
    if(body_dir.empty()){
        body_dir = "left";
    }
    if(header_dir.empty()){
        header_dir= body_dir;
    }
    
    ofstream outfile;
    outfile.open(outfile_name);
    while(getline(infile,line)){
        if((empty_line(line)|| header(line))&&x!=0){
            //cout<<temp_str<<endl;
            if(body_dir=="right"){
                outfile<<amount_space(max_width - temp_str.length())<<temp_str<<'\n';
            }
            else if(body_dir=="center"){
                outfile<<amount_space_center(temp_str.length(),max_width)<<temp_str<<amount_space_center(temp_str.length(),max_width)<<'\n';
            }
            else if(body_dir=="left"){
                outfile<<temp_str<<'\n';
            }
            x=0;
            temp_str="";
        }
        if(empty_line(line)){                             //empty line
            outfile<<'\n';
            cur_width=0;
        }
        else if(header(line)){                            //header
            if(header_dir=="right"){
                outfile<<amount_space(max_width - line.length())<<line<<'\n';
            }
            else if(header_dir=="center"){
                outfile<<amount_space_center(line.length(),max_width)<<line<<'\n';
            }
            else if(header_dir=="left"){
                outfile<<line<<amount_space(max_width - line.length())<<'\n';
            }
            //cout<<line<<endl;
            cur_width=0;
        }
        else {
            istringstream sentence(line);
            while(sentence>>word){
                if(cur_width==0){
                    temp_str+=word;
                    cur_width+=word.length()+1;
                }
                else{
                    if(cur_width+word.length()<max_width-1){
                        temp_str+=" "+word;
                        cur_width+=word.length()+1;
                    }
                    else{
                        //cout<<temp_str<<endl;
                        if(body_dir=="right"){
                            outfile<<amount_space(max_width - temp_str.length())<<temp_str<<'\n';
                        }
                        else if(body_dir=="center"){
                            outfile<<amount_space_center(temp_str.length(),max_width)<<temp_str<<amount_space_center(temp_str.length(),max_width)<<'\n';
                        }
                        else if(body_dir=="left"){
                            outfile<<temp_str<<amount_space(max_width - temp_str.length())<<'\n';
                        }
                        temp_str="";
                        cur_width=0;
                        temp_str+=word;
                        cur_width+=word.length();
                    }
                }
                x++;
            }
        }
        y++;
    }
    if((!header(line)||!empty_line(line))&&!temp_str.empty()){
        if(body_dir=="right"){
            outfile<<amount_space(max_width - temp_str.length())<<temp_str;
        }
        else if(body_dir=="center"){
            outfile<<amount_space_center(temp_str.length(),max_width)<<temp_str<<amount_space_center(temp_str.length(),max_width);
        }
        else if(body_dir=="left"){
            outfile<<temp_str<<amount_space(max_width - temp_str.length());
        }
    }
    infile.close();
    outfile.close();
    return 0;
}
