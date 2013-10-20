/*************************************************************************
	> File Name: boyaClass.cpp
	> Author: PeaBee
	> Mail: xcleung0221@gmail.com 
	> Created Time: Sun 20 Oct 2013 04:23:43 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<ctime>
using namespace std;

class Card{
public:
    Card(){}
    Card(const string &val_suit,const int val_rank){
        this->suit=val_suit;
        this->rank=val_rank;
    }

    const string &getSuit()const{ return this->suit; }
    int getRank()const{ return this->rank; }
    void setSuit(const string &val_suit) { this->suit=val_suit; }
    void setRank(const int val_rank) { this->rank=val_rank; }
    
    bool isSameSuit(const Card &val_card){
        if(this->suit==val_card.getSuit()){
            return true;
        }
        return false;
    }
    bool isSameRank(const Card &val_card){
        if(this->rank==val_card.getRank()){
            return true;
        }
        return false;
    }
	
	/*
	对象重载赋值运算符注意事项
	1.参数常量引用
	2.判断当前对象是否与参数对象指向同一个对象
	3.是否返回引用对象
	4.是否对当前对象的原有的数据空间释放掉（处理这个问题，这里运用了以下代码的方法。是可以在内存分配异常仍可工作的高级代码）
	   将当前对象与参数对象的数据进行交换，然后返回当前对象。当离开if{}代码块时 自己创建的临时对象将被系统调用析构这是内存安全的操作
	*/
    Card& operator=(const Card &val_card){
        if(this!=&val_card){
            Card myCard(val_card);
            string temp_suit=this->suit;
            int temp_rank=this->rank;

            this->suit=myCard.getSuit();
            this->rank=myCard.getRank();
            myCard.setRank(temp_rank);
            myCard.setSuit(temp_suit);
        }
        return *this;
    }
    void printCard(){
        cout<<"花色："<<this->suit<<endl;
        cout<<"面值："<<this->rank<<endl;
        cout<<endl;
    }
private:
    string suit;
    int rank;
};

//返回对象时最好不要返回引用，因为函数内部创建的对象在函数结束时会销毁的，返回引用将会引发错误
Card randomCard(){
    int rank,suit;
    string temp_suit;
    rank=1+rand()%13;
    suit=1+rand()%4;
    if(suit==1){
        temp_suit=="A";
    }else if(suit==2){
        temp_suit=="B";
    }else if(suit==3){
        temp_suit="C";
    }else if(suit==4){
        temp_suit="D";
    }
    Card card(temp_suit,rank);
    return card;
}


int main(){
    Card card_a("A",1);
    card_a.printCard();

    Card card_b;
    card_b.setRank(2);
    card_b.setSuit("B");
    card_b.printCard();

    Card card_c=card_b=card_a;
    card_a.printCard();
    card_b.printCard();
    card_c.printCard();

    cout<<card_c.isSameSuit(card_b)<<endl;
    cout<<card_c.isSameRank(card_a)<<endl;

    Card card_d= randomCard();
    Card card_e=randomCard();
    card_d.printCard();
    card_e.printCard();

    cout<<card_d.isSameSuit(card_e)<<endl;
    cout<<card_d.isSameRank(card_e)<<endl;
    return 0;
}
