#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<time.h>
#include<fstream> 
#include<Windows.h>
#include<stdlib.h>
#include<math.h>
#include<cmath>

#define MAX_num 5000
#define MAX_words 300
#define ct 1000000000
using namespace std;
//时钟变量
LARGE_INTEGER litmp;
long long time1,time2;
double dffreq,dfminus;

char word[MAX_num][MAX_words];
int number=0;

void firstpage();
void last1();
void last_seq();
void last_seq_list();
void last_Hash();

void seqlist_search();
void sq_list_search();

void seqsearch();
void seqsearch_frq();
void seqsearch_word();

void Binarysearch();
void Binarysearc_frq();
void Binarysearc_word();

void linklist_search();
void linklist_frq();
void linklist_word();


void Bitree_search();
void Bitree_word();
void Bitree_frq();

void Hash_search();
void Hashlist_search();
void Hashlist_frq();
void Hashlist_word();
void Hashlink_search();
void Hashlink_frq();
void Hashlink_word();

void Qsort(char word[]);
int partition(char word[],int low,int high);
void quicksort(char word[],int low,int high);
//——————————————————————————————————————————————————————
//显示页
void page(){																
	cout<<"\t/****基于不同策略的单次统计和检索系统****/";
	cout<<"\n"<<endl;
	cout<<"1.基于线性表的查找"<<endl;
	cout<<"2.基于二叉排序树的查找"<<endl;
	cout<<"3.基于哈希表的查找"<<endl;
	cout<<"4.退出"<<endl;
	cout<<"请按相应数字键进行选择"<<endl;
}
void page_list(){																
	cout<<"\t/****基于不同策略的单次统计和检索系统****/";
	cout<<"\n"<<endl;
	cout<<"\t\t——基于线性表的查找——";
	cout<<"\n"<<endl;
	cout<<"1.顺序表查找"<<endl;
	cout<<"2.链表查找"<<endl;
	cout<<"3.返回上一级"<<endl;
	cout<<"请按相应数字键进行选择"<<endl;
}
void page_sq_list(){															
	cout<<"\t/****基于不同策略的单次统计和检索系统****/";
	cout<<"\n"<<endl;
	cout<<"\t\t——顺序表查找——";
	cout<<"\n"<<endl;
	cout<<"1.顺序查找"<<endl;
	cout<<"2.折半查找"<<endl;
	cout<<"3.返回上一级"<<endl;
	cout<<"4.过滤低频词"<<endl;
	cout<<"请按相应数字键进行选择"<<endl;
}
void page_sq_list_seqsearch(){
	cout<<"\t/****基于不同策略的单次统计和检索系统****/";
	cout<<"\n"<<endl;
	cout<<"\t\t——顺序查找——";
	cout<<"\n"<<endl;
	cout<<"1.词频统计"<<endl;
	cout<<"2.单词查找"<<endl;
	cout<<"3.返回上一级"<<endl;
	cout<<"请按相应数字键进行选择"<<endl;

}
void page_sq_list_Binarysearch(){
	cout<<"\t/****基于不同策略的单次统计和检索系统****/";
	cout<<"\n"<<endl;
	cout<<"\t\t——折半查找——";
	cout<<"\n"<<endl;
	cout<<"1.词频统计"<<endl;
	cout<<"2.单词查找"<<endl;
	cout<<"3.返回上一级"<<endl;
	cout<<"请按相应数字键进行选择"<<endl;
}
void page_link_list(){																
	cout<<"\t/****基于不同策略的单次统计和检索系统****/";
	cout<<"\n"<<endl;
	cout<<"\t\t——链表查找——";
	cout<<"\n"<<endl;
	cout<<"1.词频统计"<<endl;
	cout<<"2.单词查找"<<endl;
	cout<<"3.返回上一级"<<endl;
	cout<<"4.过滤"<<endl;
	cout<<"请按相应数字键进行选择"<<endl;
}
void page_Bitree(){																
	cout<<"\t/****基于不同策略的单次统计和检索系统****/";
	cout<<"\n"<<endl;
	cout<<"\t\t——基于二叉排序树的查找——";
	cout<<"\n"<<endl;
	cout<<"1.词频统计"<<endl;
	cout<<"2.单词查找"<<endl;
	cout<<"3.返回上一级"<<endl;
	cout<<"4.过滤"<<endl;
	cout<<"请按相应数字键进行选择"<<endl;
}
void page_Hash(){															
	cout<<"\t/****基于不同策略的单次统计和检索系统****/";
	cout<<"\n"<<endl;
	cout<<"\t\t——基于哈希表的查找——";
	cout<<"\n"<<endl;
	cout<<"1.开放地址查找"<<endl;
	cout<<"2.链地址查找"<<endl;
	cout<<"3.返回上一级"<<endl;
	cout<<"请按相应数字键进行选择"<<endl;
}
void page_Hash_list(){
	cout<<"\t/****基于不同策略的单次统计和检索系统****/";
	cout<<"\n"<<endl;
	cout<<"\t\t——基于哈希表的开放地址查找——";
	cout<<"\n"<<endl;
	cout<<"1.词频统计"<<endl;
	cout<<"2.单词查找"<<endl;
	cout<<"3.返回上一级"<<endl;
	cout<<"4.过滤"<<endl;
	cout<<"请按相应数字键进行选择"<<endl;
}
void page_Hash_link(){
	cout<<"\t/****基于不同策略的单次统计和检索系统****/";
	cout<<"\n"<<endl;
	cout<<"\t\t——基于哈希表的链地址查找——";
	cout<<"\n"<<endl;
	cout<<"1.词频统计"<<endl;
	cout<<"2.单词查找"<<endl;
	cout<<"3.返回上一级"<<endl;
	cout<<"4.过滤"<<endl;
	cout<<"请按相应数字键进行选择"<<endl;
}
//—————————————————————————————————————————————————————
//快排
int partition(char word[][MAX_words],int low,int high){
	char pivotword[MAX_words];
	strcpy(pivotword,word[low]);
	while(low<high){
		while(low<high&&(strcmp(pivotword,word[high])<=0)) high--;
		strcpy(word[low],word[high]);	
		while(low<high&&(strcmp(pivotword,word[low])>=0)) low++;
		strcpy(word[high],word[low]);
	}
	strcpy(word[low],pivotword);
	return low;
}
void quicksort(char word[][MAX_words],int low,int high){
	if(low<high){
	int pivotloc=partition(word,low,high);
	quicksort(word,low,pivotloc-1);
	quicksort(word,pivotloc+1,high);
	}
}
void Qsort(char word[][MAX_words]){
	quicksort(word,0,number-1);
}
//清屏
void clean()
{
	system("cls");
}
//————————————————————————————————————————————————————
//线性表
void Seqlist_colation();
void seqlist_search(){
	char b;
	cin>>b;
	switch(b){
	case'1':clean();
			page_sq_list();
			sq_list_search();
			break;
	case'2':clean();
			page_link_list();
			linklist_search();
			break;
	case'3':clean();
			last1();
			break;
	default:cout<<"输入错误，请重试"<<endl;
			break;
	}
}
void last_seq(){
	page_list();
	seqlist_search();
}
void sq_list_search(){
	char c;
	cin>>c;
	switch(c){
	case'1':clean();
			page_sq_list_seqsearch();
			seqsearch();
			break;
	case'2':clean();
			page_sq_list_Binarysearch();
			Binarysearch();
			break;
	case'3':clean();
			last_seq();		
			break;
	case'4':Seqlist_colation();
			break;
	default:cout<<"输入错误，请重试"<<endl;
			break;
	}

}
void last_seq_list(){
	page_sq_list();
	sq_list_search();
}
//线性存储
typedef struct {
	char seqword[MAX_words];	
	int	times;	
}seqlist;
seqlist L[MAX_num];
//顺序查找
void seqsearch(){
//功能选择
	char d;
	cin>>d;
	switch(d){
	case'1':seqsearch_frq();								
			break;
	case'2':seqsearch_word();								
			break;
	case'3':clean();
			last_seq_list();
			break;
	default:cout<<"输入错误，请重试"<<endl;
			break;
	}
}
void seqsearch_frq(){
//存储结构
	int i=0,j=0,q=0,flag=0;
	for(i=0;i<number;i++)
	{
		for(j=0;j<q;j++){
			if(strcmp(word[i],L[j].seqword)==0) {
				flag=1;
				L[j].times++;
			}
		}
		if(!flag) {
			strcpy(L[q].seqword,word[i]);
			L[q].times=1;
			q++;
		}
		flag=0;
	}
//生成文件
	FILE *fp;
	fp=fopen("OutFile1.txt","w+");
	if(!fp)	{   
		cerr<<"Cannot open this file!"<<endl;
		exit(0);
	}
	fprintf(fp,"%d\n",q);
	for(int r=0;r<q;r++)
		fprintf(fp,"%s %d\n",L[r].seqword,L[r].times);
	fclose(fp);
	puts("词频统计完成");
}
void page_seqsearch_Suc(string s,int times,double clk,double ASL,int comp){
	cout<<"\t/****基于不同策略的单次统计和检索系统****/";
	cout<<"\n"<<endl;
	cout<<"\t\t——单次查找——";
	cout<<"\n"<<endl;
	cout<<"请输入待查找的单词："<<s<<endl;
	cout<<"此单词的词频为："<<times<<endl;
	cout<<"查找该单词所花的时间："<<clk<<endl;
	cout<<"平均查找长度："<<ASL<<endl;
	cout<<"比较次数："<<comp<<endl;
	cout<<"请按任意键返回"<<endl;
}
void page_seqsearch_Fail(string s){
	cout<<"\t/****基于不同策略的单次统计和检索系统****/";
	cout<<"\n"<<endl;
	cout<<"\t\t——单次查找——";
	cout<<"\n"<<endl;
	cout<<"请输入待查找的单词："<<s<<endl;
	cout<<"查找失败"<<endl;
	cout<<"请按任意键返回"<<endl;
}
void seqsearch_word(){
//存储结构
	int i=0,j=0,q=0,flag=0;
	for(i=0;i<number;i++)
	{
		for(j=0;j<q;j++){
			if(strcmp(word[i],L[j].seqword)==0) {
				flag=1;
				L[j].times++;
			}
		}
		if(!flag) {
			strcpy(L[q].seqword,word[i]);
			L[q].times=1;
			q++;
		}
		flag=0;
	}
//功能查找
	char s[MAX_words];
	int FLAG=0;
	double ASL=0;
	double clk=0;
	cout<<"请输入待查找的单词"<<endl;
	cin>>s;
	QueryPerformanceFrequency(&litmp); 
// 获得计数器的时钟频率 
	dffreq = (double)litmp.QuadPart; 
	QueryPerformanceCounter(&litmp);
	time1=litmp.QuadPart;
	for(int i=0;i<number;i++){
		if(strcmp(L[i].seqword,s)==0)	{
			FLAG=1;
			QueryPerformanceCounter(&litmp);
			time2=litmp.QuadPart;
			clk=(double)(1.0)*(time2-time1)*ct/dffreq;
			ASL=(q+1)/2.0;
			clean();
			page_seqsearch_Suc(s,L[i].times,clk,ASL,i+1);
			break;
		}
	}
	if(FLAG==0) {
		clean();
		page_seqsearch_Fail(s);
	}
}
//折半查找
void page_Binsearch_Suc(string s,int times,double clk,double ASL,int comp){
	cout<<"\t/****基于不同策略的单次统计和检索系统****/";
	cout<<"\n"<<endl;
	cout<<"\t\t——单词查找——";
	cout<<"\n"<<endl;
	cout<<"请输入待查找的单词："<<s<<endl;
	cout<<"此单词的词频为："<<times<<endl;
	cout<<"查找该单词所花的时间："<<clk<<endl;
	printf("平均查找长度：%.1f\n",ASL);
	cout<<"比较次数："<<comp<<endl;
	cout<<"请按任意键返回"<<endl;
}
void page_Binsearch_Fail(string s){
	cout<<"\t/****基于不同策略的单次统计和检索系统****/";
	cout<<"\n"<<endl;
	cout<<"\t\t——单词查找——";
	cout<<"\n"<<endl;
	cout<<"请输入待查找的单词："<<s<<endl;
	cout<<"查找失败"<<endl;
	cout<<"请按任意键返回"<<endl;
}
void Binarysearch(){
	char d;
	cin>>d;
	switch(d){
	case'1':Binarysearc_frq();								
			break;
	case'2':Binarysearc_word();								
			break;
	case'3':clean();
			last_seq_list();
			break;
	default:cout<<"输入错误，请重试"<<endl;
			break;
	}
}
void Binarysearc_frq(){
//存储结构
	int i=0,j=0,q=0,flag=0;
	for(i=0;i<number;i++)
	{
		for(j=0;j<q;j++){
			if(strcmp(word[i],L[j].seqword)==0) {
				flag=1;
				L[j].times++;
			}
		}
		if(!flag) {
			strcpy(L[q].seqword,word[i]);
			L[q].times=1;
			q++;
		}
		flag=0;
	}
//生成文件
	FILE *fp;
	fp=fopen("OutFile2.txt","w+");
	if(!fp)	{   
		cerr<<"Cannot open this file!"<<endl;
		exit(0);
	}
	fprintf(fp,"%d\n",q);
	for(int r=0;r<q;r++)
		fprintf(fp,"%s %d\n",L[r].seqword,L[r].times);
	fclose(fp);
	puts("词频统计完成");
}
int Binary(int q,char s[],int &comp){
	int low=0,high=0,mid=0;
	high=q-1;
	low=0;
	while(low<=high){
		comp++;
		mid=(low+high)/2;
		if(strcmp(s,L[mid].seqword)==0)  return mid;
		else if(strcmp(s,L[mid].seqword)<0) high=mid-1;
		else low=mid+1;
	}
	return -1;
}
double Bi_ASL(){
	//存储结构
	int i=0,j=0,q=0,flag=0;
	for(i=0;i<number;i++)
	{
		for(j=0;j<q;j++){
			if(strcmp(word[i],L[j].seqword)==0) {
				flag=1;
				L[j].times++;
			}
		}
		if(!flag) {
			strcpy(L[q].seqword,word[i]);
			L[q].times=1;
			q++;
		}
		flag=0;
	}
	//
	double A=0;
	for(int b=0;b<q;b++){
		int comp=0;
		Binary(q,L[b].seqword,comp);
		A+=comp;
	}
	double ASL=0;
//	cout<<q<<" "<<A;
	return ASL=double(A)/double(q);
}
void Binarysearc_word(){
//存储结构
	int i=0,j=0,q=0,flag=0;
	for(i=0;i<number;i++)
	{
		for(j=0;j<q;j++){
			if(strcmp(word[i],L[j].seqword)==0) {
				flag=1;
				L[j].times++;
			}
		}
		if(!flag) {
			strcpy(L[q].seqword,word[i]);
			L[q].times=1;
			q++;
		}
		flag=0;
	}
//单词折半查找
	char s[MAX_words];
	double clk=0;
	int FLAG=0;
	double ASL=0;
	cout<<"请输入待查找的单词"<<endl;
	cin>>s;
	QueryPerformanceFrequency(&litmp); 
// 获得计数器的时钟频率 
	dffreq = (double)litmp.QuadPart; 
	QueryPerformanceCounter(&litmp);
	time1=litmp.QuadPart;
//折半
	int comp=0;
	int B=Binary(q,s,comp);
	QueryPerformanceCounter(&litmp);
	time2=litmp.QuadPart;
	if(B!=-1)
	{
		clean();
		clk=(double)(1.0)*(time2-time1)*ct/dffreq;
		ASL=Bi_ASL();
		page_Binsearch_Suc(s,L[B].times,clk,ASL,comp);
	}
	else 
	{
		clean();
		page_Binsearch_Fail(s);
	}
}
//过滤
void Seqlist_colation(){
	//存储结构
	int i=0,j=0,q=0,flag=0;
	for(i=0;i<number;i++)
	{
		for(j=0;j<q;j++){
			if(strcmp(word[i],L[j].seqword)==0) {
				flag=1;
				L[j].times++;
			}
		}
		if(!flag) {
			strcpy(L[q].seqword,word[i]);
			L[q].times=1;
			q++;
		}
		flag=0;
	}
	int g=0;
	int rc=q;
	for(int j=0;j<rc;j++){
		double fqr=0;
		fqr=(double(L[j].times)/double(q));
		if(fqr<0.1)
		{
			g++;
			rc--;
			for(int u=j;u<rc;u++){
				strcpy(L[u].seqword,L[u+1].seqword);
				L[u].times=L[u+1].times;
			}
			j--;
		}
	}
	FILE *fp;
	fp=fopen("OutFile1(new).txt","w+");
	if(!fp)	{   
		cerr<<"Cannot open this file!"<<endl;
		exit(0);
	}
	fprintf(fp,"%d\n",rc);
	for(int r=0;r<rc;r++)
		fprintf(fp,"%s %d\n",L[r].seqword,L[r].times);
	fclose(fp);
	clean();
	puts("过滤完成，生成新文件");
}
//————————————————————————————————————————————————————————
//链式存储
typedef struct{
	char words[MAX_words];
	int times;
}node;
typedef struct Lnode{
	node data;
	struct Lnode *next;
}Lnode,*linklist;
linklist Lw;
//链过滤
void link_delete(int g,linklist &zhq){
	int x=0;
	linklist u;
	while((zhq->next)&&(x<g-1)){
		zhq=zhq->next;
		x++;
	}
	u=zhq->next;
	zhq->next=u->next;
	delete u;
	
}
void lnode_struct(linklist &Lw);
void link_colation(){
	lnode_struct(Lw);
	linklist q,v,lzy;
	q=Lw;
	int w=0;
	v=Lw;
	while(v){
		w++;
		v=v->next;
	}
	int g=0;
	int t=0;
	int z=0;
	int k[MAX_words];
	while(q){
		g++;
		double j=0;
		j=double(q->data.times)/double(w);
		if(j<0.1){
			t++;
			k[z]=g;
			z++;
		}
		q=q->next;
	}
	lzy=new Lnode;
	lzy->next=Lw;
	linklist zhq;
	zhq=lzy;
	for(int b=0;b<z;b++){
		link_delete(k[b]-b,zhq);
		zhq=lzy;
	}
	FILE *fp;
	fp=fopen("OutFile3(new).txt","w+");
	if(!fp)	{   
		cerr<<"Cannot open this file!"<<endl;
		exit(0);
	}
	fprintf(fp,"%d\n",w-t);
	for(zhq=lzy->next;zhq!=NULL;zhq=zhq->next)
		fprintf(fp,"%s %d\n",zhq->data.words,zhq->data.times);
	fclose(fp);
	puts("过滤完成");
}
//链存储
void lnode_struct(linklist &Lw){
	int flag=0;
	int i=0;
	linklist p,q;
	Lw=new Lnode;
	Lw->next=NULL;
	strcpy(Lw->data.words,word[0]);
	Lw->data.times=1;
	p=Lw;
	while(i<number-1){
		i++;
		while(p){
			if(strcmp(word[i],p->data.words)==0)
			{
				flag=1;
				p->data.times++;
			}
			q=p;
			p=p->next;
		}
		if(flag==0)
		{
			p=new Lnode;
			strcpy(p->data.words,word[i]);
			p->data.times=1;
			p->next=NULL;
			q->next=p;
		}
		p=Lw;
		flag=0;
	}
}
//链词频
void linklist_search(){
	lnode_struct(Lw);
	char c;
	cin>>c;
	switch(c){
	case'1':linklist_frq();								
			break;
	case'2':linklist_word();							
			break;
	case'3':clean();
			last_seq();
			break;
	case'4':link_colation();
			break;
	default:cout<<"输入错误，请重试"<<endl;
			break;
	}
}
void linklist_frq(){
	int w=0;
	linklist q;
	q=Lw;
	while(q){
		w++;
		q=q->next;
	}
	FILE *fp;
	fp=fopen("OutFile3.txt","w+");
	if(!fp)	{   
		cerr<<"Cannot open this file!"<<endl;
		exit(0);
	}
	fprintf(fp,"%d\n",w);
	for(q=Lw;q!=NULL;q=q->next)
		fprintf(fp,"%s %d\n",q->data.words,q->data.times);
	fclose(fp);
	puts("词频统计完成");
}
//链查找
void page_Lnode_Suc(string s,int times,double clk,double ASL,int comp){
	cout<<"\t/****基于不同策略的单次统计和检索系统****/";
	cout<<"\n"<<endl;
	cout<<"\t\t——单词查找——";
	cout<<"\n"<<endl;
	cout<<"请输入待查找的单词："<<s<<endl;
	cout<<"此单词的词频为："<<times<<endl;
	cout<<"查找该单词所花的时间："<<clk<<endl;
	cout<<"平均查找长度："<<ASL<<endl;
	cout<<"比较次数："<<comp<<endl;
	cout<<"请按任意键返回"<<endl;
}
void page_Lnode_Fail(string s){
	cout<<"\t/****基于不同策略的单次统计和检索系统****/";
	cout<<"\n"<<endl;
	cout<<"\t\t——单词查找——";
	cout<<"\n"<<endl;
	cout<<"请输入待查找的单词："<<s<<endl;
	cout<<"查找失败"<<endl;
	cout<<"请按任意键返回"<<endl;
}
void linklist_word(){
	char s[MAX_words];
	double clk=0;
	int FLAG=0;
	int comp=0;
	double ASL=0;
	linklist q;
	cout<<"请输入待查找的单词"<<endl;
	cin>>s;
	QueryPerformanceFrequency(&litmp); 
// 获得计数器的时钟频率 
	dffreq = (double)litmp.QuadPart; 
	QueryPerformanceCounter(&litmp);
	time1=litmp.QuadPart;
	int w=0;
	q=Lw;
	while(q){
		w++;
		q=q->next;
	}
	for(q=Lw;q!=NULL;q=q->next){
		comp++;
		if(strcmp(q->data.words,s)==0) 
		{
			QueryPerformanceCounter(&litmp);
			time2=litmp.QuadPart;
			clk=(double)(1.0)*(time2-time1)*ct/dffreq;
			FLAG=1;
			clean();
			ASL=(w+1)/2.0;
			page_Lnode_Suc(s,q->data.times,clk,ASL,comp);
		}
	}
	if(FLAG==0){
		clean();
		page_Lnode_Fail(s);
	}
}
//————————————————————————————————————————————————————————
//二叉树
typedef struct{
	char word[MAX_words];
	int times;
}Info;
typedef struct BSTnode{
	Info data;
	struct BSTnode *lchild,*rchild;
}BSTnode,*BSTree;
BSTree T,HQ,HZ;
//二叉树存储
void Insert_BST(BSTree &T,char M[]){
	BSTree s;
	if(!T){
		s=new BSTnode;
		s->data.times=1;
		strcpy(s->data.word,M);
		s->lchild=NULL;
		s->rchild=NULL;
		T=s;
	}
	else if(strcmp(M,T->data.word)<0)
		Insert_BST(T->lchild,M);
	else if(strcmp(M,T->data.word)>0)
		Insert_BST(T->rchild,M);
	else 
		T->data.times++;
}
void BST_struct(BSTree &T){
	T=NULL;
	char M[MAX_words];
	int i=0;
	while(i<number){
		strcpy(M,word[i]);
		Insert_BST(T,M);
		i++;
	}
}
//二叉过滤
void BT_colation();
void BT_colation_search(BSTree Q,int w);
void Bitree_search(){
	BST_struct(T);
	char b;
	cin>>b;
	switch(b){
	case'1':Bitree_frq();							
			break;
	case'2':Bitree_word();							
			break;
	case'3':clean();
			last1();
			break;
	case'4':BT_colation();
			break;
	default:cout<<"输入错误，请重试"<<endl;
			break;
	}
}
void BT_delete(BSTree &T,char key[]){
	BSTree p,f,q,s;
	p=T;
	f=NULL;
	while(p)
	{
		if(strcmp(p->data.word,key)==0)
			break;
		f=p;
		if(strcmp(p->data.word,key)>0)
			p=p->lchild;
		else p=p->rchild;
	}
	if(!p) return;
	q=p;
	if((p->lchild)&&(p->rchild))
	{
		s=p->lchild;
		while(s->rchild)
		{
			q=s;
			s=s->rchild;
		}
		strcpy(p->data.word,s->data.word);
		if(q!=p)
			q->rchild=s->lchild;
		else q->lchild=s->lchild;
		delete s;
		return;
	}
	else if(!p->rchild){
		p=p->lchild;
	}
	else if(!p->lchild){
		p=p->rchild;
	}
	if(!f) T=p;
	else if(q==f->lchild) f->lchild=p;
	else f->rchild=p;
	delete q;
}
void Gothrough_BT(BSTree T,int &w);
void BT_colation_search(BSTree Q,int w){
	if(!Q) return;
	else{
	BT_colation_search(Q->lchild,w);
		if((double(Q->data.times)/double(w))<0.1)
	{	
		BT_delete(T,Q->data.word);
	}
	BT_colation_search(Q->rchild,w);
	}
}
void Gosearch_BT(BSTree T,FILE *fp);
void BT_colation(){
	BSTree Q;
	BST_struct(Q);
	int w=0;
	Gothrough_BT(Q,w);
	BT_colation_search(Q,w);
	FILE *fp;
	fp=fopen("OutFile4(new).txt","w+");
	if(!fp)	{   
		cerr<<"Cannot open this file!"<<endl;
		exit(0);
	}
	w=0;
	Gothrough_BT(T,w);
	fprintf(fp,"%d\n",w);
	Gosearch_BT(T,fp);
	fclose(fp);
	puts("过滤完毕");
}
//二叉词频
void Gothrough_BT(BSTree T,int &w){
	if(!T) return;
	else{
	Gothrough_BT(T->lchild,w);
	w++;
	Gothrough_BT(T->rchild,w);
	}
}
void Gosearch_BT(BSTree T,FILE *fp){
	if(!T) return;
	else 
	{
		Gosearch_BT(T->lchild,fp);
		fprintf(fp,"%s %d\n",T->data.word,T->data.times);
		Gosearch_BT(T->rchild,fp);
	}
}
void Bitree_frq(){
	int w=0;
	Gothrough_BT(T,w);
	FILE *fp;
	fp=fopen("OutFile4.txt","w+");
	if(!fp)	{   
		cerr<<"Cannot open this file!"<<endl;
		exit(0);
	}
	fprintf(fp,"%d\n",w);
	Gosearch_BT(T,fp);
	fclose(fp);
	puts("词频统计完成");
}
//二叉查找
void Gothrough_search(BSTree T,char s[],int &FLAG,int &compare,int &times){
	if(!T) return;
	else{
		compare++;
		if(strcmp(s,T->data.word)==0) 
		{
			times=T->data.times;
			FLAG=1;
			return;
		}
		else if(strcmp(s,T->data.word)<0)
			Gothrough_search(T->lchild,s,FLAG,compare,times);
		else if(strcmp(s,T->data.word)>0)
			Gothrough_search(T->rchild,s,FLAG,compare,times);
	}
}
void page_BTS_Suc(char s[],double clk,double ASL,int comp,int times){
	cout<<"\t/****基于不同策略的单次统计和检索系统****/";
	cout<<"\n"<<endl;
	cout<<"\t\t——单词查找——";
	cout<<"\n"<<endl;
	cout<<"请输入待查找的单词："<<s<<endl;
	cout<<"此单词的词频为："<<times<<endl;
	cout<<"查找该单词所花的时间："<<clk<<endl;
	printf("平均查找长度：%.1f\n",ASL);
	cout<<"比较次数："<<comp<<endl;
	cout<<"请按任意键返回"<<endl;
}
void page_BTS_Fail(char s[]){
	cout<<"\t/****基于不同策略的单次统计和检索系统****/";
	cout<<"\n"<<endl;
	cout<<"\t\t——单词查找——";
	cout<<"\n"<<endl;
	cout<<"请输入待查找的单词："<<s<<endl;
	cout<<"查找失败"<<endl;
	cout<<"请按任意键返回"<<endl;
}
void BT_ASL_Search(BSTree T,char s[],int &comp){
	if(!T) return;
	else{
		comp++;
		if(strcmp(s,T->data.word)==0) 
			return;
		else if(strcmp(s,T->data.word)<0)
			BT_ASL_Search(T->lchild,s,comp);
		else if(strcmp(s,T->data.word)>0)
			BT_ASL_Search(T->rchild,s,comp);
	}
}
void BT_ASL(BSTree T,int &comp,int &A,BSTree HQ){
	if(!T) return;
	else{
	BT_ASL(T->lchild,comp,A,HQ);
	BT_ASL_Search(HQ,T->data.word,comp);
	A+=comp;
	comp=0;
	BT_ASL(T->rchild,comp,A,HQ);
	}
}
void Bitree_word(){
	char s[MAX_words];
	double clk;
	int FLAG=0;
	int comp=0;
	double ASL=0;
	linklist q;
	int times=0;
	cout<<"请输入待查找的单词"<<endl;
	cin>>s;
	QueryPerformanceFrequency(&litmp); 
// 获得计数器的时钟频率 
	dffreq = (double)litmp.QuadPart; 
	QueryPerformanceCounter(&litmp);
	time1=litmp.QuadPart;
	int compare=0;
	Gothrough_search(T,s,FLAG,compare,times);
	QueryPerformanceCounter(&litmp);
	time2=litmp.QuadPart;
	int w=0;
	Gothrough_BT(T,w);
	if(FLAG==1)
	{
		clean();
		clk=(double)(1.0)*(time2-time1)*ct/dffreq;
		int A=0;

		HQ=T;
		BT_ASL(T,comp,A,HQ);
		cout<<A<<" "<<w<<endl;
		ASL=1.0*A/w;
		page_BTS_Suc(s,clk,ASL,compare,times);
	}
	else 
	{
		clean();
		page_BTS_Fail(s);
	}
}
//————————————————————————————————————————————————————————
//哈希开放地址
#define m 200
typedef struct{
	char key[MAX_words];
	int orginal;
	int times;
}HashTable;
HashTable HT[m];
//哈希开放地址存储
int Hash(char w[]){
	int q=0;
	q=strlen(w);
	int h=0;
	h=w[0]+w[q-1]+q;
	h=h%193;
	return h;
}
void HashTable_struct(HashTable HT[]){
	int i=0;
	int h=0;
	char ch[]="NULL";
	// set NULL
	for(i=0;i<m;i++){
		strcpy(HT[i].key,ch);
	}
	for(i=0;i<number;i++){
		h=Hash(word[i]);
		int flag=0;
		//查重
		for(int j=0;j<m;j++){
			if(strcmp(HT[j].key,word[i])==0){
				flag=1;
				HT[j].times++;
			}
		}
		//无重后写入
	 if(flag==0){
		 //为空时写入
		if(strcmp(HT[h].key,ch)==0)
		{
			strcpy(HT[h].key,word[i]);
			HT[h].times=1;
			HT[h].orginal=i;
		}
		//不为空的时候寻找
		else if(strcmp(HT[h].key,ch)!=0)
		{
			int d=1;
			//注意m太小的时候会出现问题
			while((strcmp(HT[h].key,ch)!=0)){
				h=(h+d)%m;
			}
			strcpy(HT[h].key,word[i]);
			HT[h].times=1;
			HT[h].orginal=i;
		}
	 }
	}
//	for(int g=0;g<m;g++)
//		cout<<HT[g].key<<" "<<HT[g].times<<endl;
}
void Hash_search(){
	char b;
	cin>>b;
	switch(b){
	case'1':clean();
			page_Hash_list();							
			Hashlist_search();
			break;
	case'2':clean();
			page_Hash_link();							
			Hashlink_search();
			break;
	case'3':clean();
			last1();
			break;
	default:cout<<"输入错误，请重试"<<endl;
			break;
	}
}
void last_Hash(){
	page_Hash();
	Hash_search();
}
//哈希过滤
void Hashlist_colation();
void Hashlist_search(){
	HashTable_struct(HT);
	char c;
	cin>>c;
	switch(c){
	case'1':Hashlist_frq();							
			break;
	case'2':Hashlist_word();							
			break;
	case'3':clean();
			last_Hash();
			break;
	case '4':Hashlist_colation();
			break;
	default:cout<<"输入错误，请重试"<<endl;
			break;
	}
}
void Hashlist_colation(){
	int w=0;
	char ch[]="NULL";
	// HT HashTable
	for(int i=0;i<m;i++){
		if(strcmp(HT[i].key,ch)!=0)
			w++;
	}
	seqlist HL[MAX_words];
	// set NULL
	for(int a=0;a<number;a++){
		strcpy(HL[a].seqword,ch);
	}
	for(int u=0;u<m;u++){
		if(double(HT[u].times)/double(w)<0.1)
		{
			strcpy(HT[u].key,ch);
		}
	}
	for(int u=0;u<m;u++){
		if(strcmp(HT[u].key,ch)!=0)
		{
			strcpy(HL[HT[u].orginal].seqword,word[HT[u].orginal]);
			HL[HT[u].orginal].times=HT[u].times;
		}
	}
	FILE *fp;
	fp=fopen("OutFile5(new).txt","w+");
	if(!fp)	{   
		cerr<<"Cannot open this file!"<<endl;
		exit(0);
	}
	w=0;
	for(int i=0;i<m;i++){
		if(strcmp(HT[i].key,ch)!=0)
			w++;
	}
	fprintf(fp,"%d\n",w);
	for(int j=0;j<number;j++){
		if(strcmp(HL[j].seqword,ch)!=0)
			fprintf(fp,"%s %d\n",HL[j].seqword,HL[j].times);
	}
	fclose(fp);
	puts("过滤完成");
}
//哈希词频
void Hashlist_frq(){
	int w=0;
	char ch[]="NULL";
	// HT HashTable
	for(int i=0;i<m;i++){
		if(strcmp(HT[i].key,ch)!=0)
			w++;
	}
	FILE *fp;
	fp=fopen("OutFile5.txt","w+");
	if(!fp)	{   
		cerr<<"Cannot open this file!"<<endl;
		exit(0);
	}
	fprintf(fp,"%d\n",w);
	// HL HashTable_List
	// notice the stack overflow
	seqlist HL[MAX_words];
	// set NULL
	for(int a=0;a<number;a++){
		strcpy(HL[a].seqword,ch);
	}
	// assign
	for(int u=0;u<m;u++){
		if(strcmp(HT[u].key,ch)!=0)
		{
			strcpy(HL[HT[u].orginal].seqword,word[HT[u].orginal]);
			HL[HT[u].orginal].times=HT[u].times;
		}
	}
	for(int j=0;j<number;j++){
		//
		if(strcmp(HL[j].seqword,ch)!=0)
			fprintf(fp,"%s %d\n",HL[j].seqword,HL[j].times);
	}
	fclose(fp);
	puts("词频统计完成");
}
//哈希查找
int Hash_Search(int &h,char s[],int &comp){
	char ch[]="NULL";
	comp++;
	if(strcmp(s,HT[h].key)==0)
		return 1;
	else if(strcmp(ch,HT[h].key)==0)
		return 0;
	else 
	{
		for(int i=1;i<m;i++){
			h=(h+1)%m;
			if(strcmp(HT[h].key,s)==0)		
				return 1;
			else if(strcmp(HT[h].key,ch)==0) 
				return 0;
		}
	}
}
void page_Hash_Suc(char s[],double clk,double ASL,int comp,int times){
	cout<<"\t/****基于不同策略的单次统计和检索系统****/";
	cout<<"\n"<<endl;
	cout<<"\t\t——单词查找——";
	cout<<"\n"<<endl;
	cout<<"请输入待查找的单词："<<s<<endl;
	cout<<"此单词的词频为："<<times<<endl;
	cout<<"查找该单词所花的时间："<<clk<<endl;
	cout<<"平均查找长度："<<ASL<<endl;
	cout<<"比较次数："<<comp<<endl;
	cout<<"请按任意键返回"<<endl;
}
void page_Hash_Fail(char s[]){
	cout<<"\t/****基于不同策略的单次统计和检索系统****/";
	cout<<"\n"<<endl;
	cout<<"\t\t——单词查找——";
	cout<<"\n"<<endl;
	cout<<"请输入待查找的单词："<<s<<endl;
	cout<<"查找失败"<<endl;
	cout<<"请按任意键返回"<<endl;
}
double ASL_HashList(){
	int comp=0;
	int h=0;
	int w=0;
	double A=0;
	char ch[]="NULL";
	int FLAG=0;
	for(int i=0;i<m;i++){
		if(strcmp(HT[i].key,ch)!=0)
		{
			w++;
			h=Hash(HT[i].key);
			FLAG=Hash_Search(h,HT[i].key,comp);
			if(FLAG)
				A+=comp;
			comp=0;
		}
	}
	return A/w;
}
void Hashlist_word(){
	char s[MAX_words];
	double clk;
	int FLAG=0;
	int comp=0;
	int h=0;
	double ASL=0;
	int times=0;
	cout<<"请输入待查找的单词"<<endl;
	cin>>s;
	QueryPerformanceFrequency(&litmp); 
// 获得计数器的时钟频率 
	dffreq = (double)litmp.QuadPart; 
	QueryPerformanceCounter(&litmp);
	time1=litmp.QuadPart;
	h=Hash(s);
	FLAG=Hash_Search(h,s,comp);
	QueryPerformanceCounter(&litmp);
	time2=litmp.QuadPart;
	if(FLAG==1)
	{
		clean();
		clk=(double)(1.0)*(time2-time1)*ct/dffreq;
		ASL=ASL_HashList();
		page_Hash_Suc(s,clk,ASL,comp,HT[h].times);
	}
	else if(!FLAG)
	{
		clean();
		page_Hash_Fail(s);
	}
}
//—————————————————————————————————————————————————————————
//哈希链地址
typedef struct Hnode{
	char word[MAX_words];
	int times;
	int flag;
	int oginal;
	int longth;
	struct Hnode *next;
}Hnode,*Hlink;
Hnode list[m];
//哈希链地址存储
void Hashlink_struct(Hnode list[]){
	int i=0,h=0;
	int FLAG=0;
	for(i=0;i<m;i++){
		list[i].times=0;
		list[i].flag=0;
		list[i].longth=0;	
		list[i].oginal=0;
		list[i].next=NULL;
	}
	for(i=0;i<number;i++){
		h=Hash(word[i]);
		//
		if(!list[h].flag){
			strcpy(list[h].word,word[i]);
			list[h].oginal=i;
			list[h].flag=1;
			list[h].times=1;
			list[h].longth=1;
		}
		else if(list[h].flag&&strcmp(list[h].word,word[i])==0)
		{
			list[h].times++;
		}
		else if(list[h].flag&&strcmp(list[h].word,word[i])!=0){			
			int k=0;
			Hlink q;
			q=list[h].next;
			while(q){
				if(strcmp(q->word,word[i])==0)
				{
					k=1;
					q->times++;
					//
					break;
				}
				q=q->next;
			}
			if(!k){
				Hlink p;
				p=new Hnode;
				p->next=list[h].next;
				list[h].next=p;
				strcpy(p->word,word[i]);
				p->oginal=i;
				list[h].longth++;
				//
				p->times=1;			
			}
		}
	}

	

}
//哈希链过滤
void Hashlink_colation(){
	char ch[]="NULL";
	seqlist Hf[MAX_words];
	for(int c=0;c<number;c++){
		strcpy(Hf[c].seqword,ch);
	}
	int r=0;
	for(int i=0;i<m;i++){
		if(list[i].flag){
				r++;
			}
			if(list[i].longth!=1)
			{
				Hlink p;
				p=list[i].next;
				while(p){
					r++;
					p=p->next;
				}
			}
	}
	int z=0;
	for(int i=0;i<m;i++){
		if(list[i].flag){
			if(double(list[i].times)/double(r)<0.1)
			{
				strcpy(list[i].word,ch);
				z++;
			}
			if(list[i].longth!=1)
			{
				Hlink p;
				p=list[i].next;
				while(p){
					if(double(p->times)/double(r)<0.1)
					{	strcpy(p->word,ch);
						z++;
					}
					p=p->next;
				}
			}
		}
	}
	for(int i=0;i<m;i++){
		if(list[i].flag){
			if(strcmp(list[i].word,ch)!=0){
				strcpy(Hf[list[i].oginal].seqword,word[list[i].oginal]);
				Hf[list[i].oginal].times=list[i].times;
			}
			if(list[i].longth!=1)
			{
				Hlink p;
				p=list[i].next;
				while(p){
					if(strcmp(p->word,ch)!=0)
					{
						strcpy(Hf[p->oginal].seqword,word[p->oginal]);
						Hf[p->oginal].times=p->times;
					}
					p=p->next;
				}
			}
		}
	}
	FILE *fp;
	fp=fopen("OutFile6(new).txt","w+");
	if(!fp)	{   
		cerr<<"Cannot open this file!"<<endl;
		exit(0);
	}
	fprintf(fp,"%d\n",r-z);
	for(int j=0;j<number;j++){
		if(strcmp(Hf[j].seqword,ch)!=0)
			fprintf(fp,"%s %d\n",Hf[j].seqword,Hf[j].times);
	}
	fclose(fp);
	puts("过滤完成");
}
void Hashlink_search(){
	char c;
	cin>>c;
	Hashlink_struct(list);
	switch(c){
	case'1':Hashlink_frq();							
			break;
	case'2':Hashlink_word();						
			break;
	case'3':clean();
			last_Hash();
			break;
	case'4':Hashlink_colation();
			break;
	default:cout<<"输入错误，请重试"<<endl;
			break;
	}	
}
///哈希链地址词频
void Hashlink_frq(){
	int i=0,r=0;
	char ch[]="NULL";
	seqlist Hf[MAX_words];
	for(int c=0;c<number;c++){
		strcpy(Hf[c].seqword,ch);
	}
	for(i=0;i<m;i++){
		if(list[i].flag){
			//first
			r++;
			strcpy(Hf[list[i].oginal].seqword,word[list[i].oginal]);
			Hf[list[i].oginal].times=list[i].times;
			if(list[i].longth!=1)
			{
				Hlink p;
				p=list[i].next;
				while(p){
					r++;
					strcpy(Hf[p->oginal].seqword,word[p->oginal]);
					Hf[p->oginal].times=p->times;
					p=p->next;
				}
			}
		}
	}	// for
	FILE *fp;
	fp=fopen("OutFile6.txt","w+");
	if(!fp)	{   
		cerr<<"Cannot open this file!"<<endl;
		exit(0);
	}
	fprintf(fp,"%d\n",r);
	for(int j=0;j<number;j++){
		//
		if(strcmp(Hf[j].seqword,ch)!=0)
			fprintf(fp,"%s %d\n",Hf[j].seqword,Hf[j].times);
	}
	fclose(fp);
	puts("词频统计完成");
}
void page_HashLink_Suc(char s[],double clk,double ASL,int comp,int times){
	cout<<"\t/****基于不同策略的单次统计和检索系统****/";
	cout<<"\n"<<endl;
	cout<<"\t\t——单词查找——";
	cout<<"\n"<<endl;
	cout<<"请输入待查找的单词："<<s<<endl;
	cout<<"此单词的词频为："<<times<<endl;
	cout<<"查找该单词所花的时间："<<clk<<endl;
	cout<<"平均查找长度："<<ASL<<endl;
	cout<<"比较次数："<<comp<<endl;
	cout<<"请按任意键返回"<<endl;
}
void page_HashLink_Fail(char s[]){
	cout<<"\t/****基于不同策略的单次统计和检索系统****/";
	cout<<"\n"<<endl;
	cout<<"\t\t——单词查找——";
	cout<<"\n"<<endl;
	cout<<"请输入待查找的单词："<<s<<endl;
	cout<<"查找失败"<<endl;
	cout<<"请按任意键返回"<<endl;
}
void Hashlink_Search(char s[],int &FLAG,int &e){
	int h=0;
	h=Hash(s);
	if(list[h].flag==0) FLAG=0;
	else {
		if(strcmp(list[h].word,s)==0)
			FLAG=1;
		else if((strcmp(list[h].word,s)!=0)&&(list[h].longth==1))
			FLAG=0;
		else if((strcmp(list[h].word,s)!=0)&&(list[h].longth!=1))
		{
			Hlink x;
			x=list[h].next;
			while(x){
				e++;
				if(strcmp(x->word,s)==0)
						FLAG=1;
				if(FLAG==1)
						break;	
				x=x->next;
			}
		}
	}
}
double ASL_HashLink(){
	HashTable_struct(HT);
	int comp=0;
	int h=0;
	int w=0;
	double A=0;
	char ch[]="NULL";
	int FLAG=0;
	for(int i=0;i<m;i++){
		if(strcmp(HT[i].key,ch)!=0)
		{
			int FLAG=0;
			int e=1;
			w++;
			Hashlink_Search(HT[i].key,FLAG,e);
			if(FLAG)
				A+=e;
		}
	}
	return A/w;
}
//哈希链地址查找
void Hashlink_word(){
	char s[MAX_words];
	double clk;
	int FLAG=0;
	int comp=0;
	double ASL=0;
	int times=0;
	cout<<"请输入待查找的单词"<<endl;
	cin>>s;
	clean();
	QueryPerformanceFrequency(&litmp); 
// 获得计数器的时钟频率 
	dffreq = (double)litmp.QuadPart; 
	QueryPerformanceCounter(&litmp);
	time1=litmp.QuadPart;
// hash hanshu
	int h=0;
	int e=1;
	h=Hash(s);
	if(list[h].flag==0) FLAG=0;
	else {
		if(strcmp(list[h].word,s)==0)
			FLAG=1;
		else if((strcmp(list[h].word,s)!=0)&&(list[h].longth==1))
			FLAG=0;
		else if((strcmp(list[h].word,s)!=0)&&(list[h].longth!=1))
		{
			Hlink x;
			x=list[h].next;
			while(x){
				e++;
				if(strcmp(x->word,s)==0)
						FLAG=1;
				if(FLAG==1)
						break;	
				x=x->next;
			}
		}
	}
	QueryPerformanceCounter(&litmp);
	time2=litmp.QuadPart;
	if(FLAG){
		clean();
		clk=(double)(1.0)*(time2-time1)*ct/dffreq;
		if(e==1){
			ASL=ASL_HashLink();
			comp=1;
			page_HashLink_Suc(s,clk,ASL,comp,list[h].times);
		}
		else if(e>1)
		{
			ASL=ASL_HashLink();		
			comp=e;
			int d=2;
			Hlink v;
			v=list[h].next;
			while(d<e){
				v=v->next;
				d++;
			}
			page_HashLink_Suc(s,clk,ASL,comp,v->times);
		}
	}
	else if(!FLAG){
		clean();
		page_HashLink_Fail(s);
	}
}
//————————————————————————————————————————————————————————
//输入单词
void last1(){
	firstpage();
}
void firstpage(){
	char a;
	page();
	cin>>a;
	switch(a){
		case '1':clean();
				 page_list();								
				 seqlist_search();
				 break;
		case '2':clean();
				 page_Bitree();								
				 Bitree_search();
				 break;	
		case '3':clean();
				 page_Hash();							
				 Hash_search();
				 break;
		case '4':cout<<"欢迎再次使用，再见"<<endl;		
				 exit(0);
		default: cout<<"请选择正确操作"<<endl;
				 break;
	}
}
int judge(char ch){
	if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
		return 1;
	else return 0;
}
void input(char word[][MAX_words],int &number){
	char ch;
	int i=0;
	int flag=0;
	FILE *fp;
	fp=fopen("InFile.txt", "r");
	if(!fp)	{   
		cerr<<"Cannot open this file!"<<endl;
		exit(0);
	}	
	while(!feof(fp)){
		fscanf(fp,"%c",&ch);
		if(judge(ch)){
			flag=1;
			if(ch>='A'&&ch<='Z') ch-='A'-'a';
			word[number][i]=ch;
			i++;
		}
		if(!judge(ch)&&flag) {
			word[number][i]='\0';
			number++;
			flag=0;
			i=0;
		}
	}
	Qsort(word);
//	cout<<number<<endl;
//	for(int i=0;i<number;i++)
//		cout<<word[i]<<endl;
}
//主函数
int main(){
	input(word,number);
	while(1){
		firstpage();
	}
	return 0;
}



