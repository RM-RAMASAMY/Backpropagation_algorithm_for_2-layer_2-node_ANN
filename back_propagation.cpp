#include<bits/stdc++.h>
using namespace std;
#define e 2.71828

struct ele
{
	float x1,x2,d1,d2,h1,h2,s1,s2,v1,v2,y1,y2,e1,e2,deli1,deli2,delj1,delj2,w11,w12,w21,w22,m11,m12,m21,m22;
	void input()
	{
		cout<<"\nenter the value of x1: ";cin>>x1;
		cout<<"enter the value of x2: ";cin>>x2;
		cout<<"enter the value of d1: ";cin>>d1;
		cout<<"enter the value of d2: ";cin>>d2;
	}
	
	void gen_h()
	{
		h1=(m11*x1)+(m12*x2);
		h2=(m21*x1)+(m22*x2);
	}
	void gen_v()
	{
		v1=1/(1+pow(e,(-h1)));
		v2=1/(1+pow(e,(-h2)));
	}
	void gen_s()
	{
		s1=(w11*v1)+(w12*v2);
		s2=(w21*v1)+(w22*v2);
	}
	void gen_y()
	{
		y1=1/(1+pow(e,(-s1)));
		y2=1/(1+pow(e,(-s2)));
	}
	void gen_err()
	{
		e1=d1-y1;
		e2=d2-y2;
	}
	void gen_deli()
	{
		deli1=y1*(1-y1)*(d1-y1);
		deli2=y2*(1-y2)*(d2-y2);
	}
	void calc_new_w()
	{
		w11=w11+(deli1*v1);
		w12=w12+(deli1*v2);
		w21=w21+(deli2*v1);
		w22=w22+(deli2*v2);
	}
	void gen_delj()
	{
		delj1=v1*(1-v1)*((deli1*w11)+(deli2*w21));
		delj2=v2*(1-v2)*((deli1*w12)+(deli2*w22));
	}
	void calc_new_m()
	{
		m11=m11+(delj1*x1);
		m12=m12+(delj1*x2);
		m21=m21+(delj2*x1);
		m22=m22+(delj2*x2);
	}
	
};


int main()
{
	int n,flag=-1;
	cout<<"enter the number of records: ";cin>>n;
	struct ele *a=new ele[n];
	for(int i=0;i<n;++i)
	{
		cout<<"\nenter the data set corresponding to record "<<i+1<<" : "; 
		a[i].input();
	}
	
	cout<<"\nenter the initial weight value of m11 :";
	cin>>a[0].m11;
	cout<<"enter the initial weight value of m12 :";
	cin>>a[0].m12;
	cout<<"enter the initial weight value of m21 :";
	cin>>a[0].m21;
	cout<<"enter the initial weight value of m22 :";
	cin>>a[0].m22;
	cout<<"\nenter the initial weight value of w11 :";
	cin>>a[0].w11;
	cout<<"enter the initial weight value of w12 :";
	cin>>a[0].w12;
	cout<<"enter the initial weight value of w21 :";
	cin>>a[0].w21;
	cout<<"enter the initial weight value of w22 :";
	cin>>a[0].w22;
	a[0].gen_h();
	a[0].gen_v();
	a[0].gen_s();
	a[0].gen_y();
	a[0].gen_deli();
	a[0].calc_new_w();
	a[0].gen_delj();
	a[0].calc_new_m();
//	cout<<"\nweights after pattern "<<1<<" : \n";
//	cout<<"\n w: "<<a[0].w11<<" "<<a[0].w12<<" "<<a[0].w21<<" "<<a[0].w22;
//	cout<<"\n\n m: "<<a[0].m11<<" "<<a[0].m12<<" "<<a[0].m21<<" "<<a[0].m22;
	for(int l=1;l<n;++l)
	{
		a[l].w11=a[l-1].w11;
		a[l].w12=a[l-1].w12;
		a[l].w21=a[l-1].w21;
		a[l].w22=a[l-1].w22;
		a[l].m11=a[l-1].m11;
		a[l].m12=a[l-1].m12;
		a[l].m21=a[l-1].m21;
		a[l].m22=a[l-1].m22;
		a[l].gen_h();
		a[l].gen_v();
		a[l].gen_s();
		a[l].gen_y();
		a[l].gen_deli();
		a[l].calc_new_w();
		a[l].gen_delj();
		a[l].calc_new_m();
//		cout<<"\n\nweights after pattern "<<l+1<<" : \n";
//		cout<<"\n w: "<<a[l].w11<<" "<<a[l].w12<<" "<<a[l].w21<<" "<<a[l].w22;
//		cout<<"\n\n m: "<<a[l].m11<<" "<<a[l].m12<<" "<<a[l].m21<<" "<<a[l].m22;
	}
	int c=0,iteration=1;
	while(flag!=0)
	{
		
		if(c==0)
		{
			a[c].w11=a[n-1].w11;
			a[c].w12=a[n-1].w12;
			a[c].w21=a[n-1].w21;
			a[c].w22=a[n-1].w22;
			a[c].m11=a[n-1].m11;
			a[c].m12=a[n-1].m12;
			a[c].m21=a[n-1].m21;
			a[c].m22=a[n-1].m22;
			
		}
		else
		{
			a[c].w11=a[c-1].w11;
			a[c].w12=a[c-1].w12;
			a[c].w21=a[c-1].w21;
			a[c].w22=a[c-1].w22;
			a[c].m11=a[c-1].m11;
			a[c].m12=a[c-1].m12;
			a[c].m21=a[c-1].m21;
			a[c].m22=a[c-1].m22;
		}
		
		a[c].gen_h();
		a[c].gen_v();
		a[c].gen_s();
		a[c].gen_y();
		a[c].gen_err();
		a[c].gen_deli();
		a[c].calc_new_w();
		a[c].gen_delj();
		a[c].calc_new_m();
//		cout<<"\n\nweights after pattern "<<c+1<<" : \n";
//		cout<<"\n w: "<<a[c].w11<<" "<<a[c].w12<<" "<<a[c].w21<<" "<<a[c].w22;
//		cout<<"\n\n m: "<<a[c].m11<<" "<<a[c].m12<<" "<<a[c].m21<<" "<<a[c].m22;
		int q1=int(a[c].e1*100);
		int q2=int(a[c].e2*100);
		
		
		if(((q1==0)&&(q2==0))||(iteration>=1000000))
		{
			flag=0;
			cout<<"\n rusultant weights are: \n";
			cout<<"\n w: "<<a[c].w11<<" "<<a[c].w12<<" "<<a[c].w21<<" "<<a[c].w22;
			cout<<"\n\n m: "<<a[c].m11<<" "<<a[c].m12<<" "<<a[c].m21<<" "<<a[c].m22;
			
			cout<<"\n\n number of iterations took : "<<iteration;
			cout<<"\n\n corresponding error factor are: "<<a[c].e1<<" "<<a[c].e2;
			
		}
		c++;
		if(c==(n))
		{
			c=0;
			iteration++;
		}
	}
	return 0;
}
