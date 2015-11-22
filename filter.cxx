#include <iostream>
//#include <string>
#include <fstream>



//verwendete Funktionen:

void copy_txt (double*, const int );
void filter_nois(double *p, int const N);
void delete_arr(double*);
void file_make( double *p, int const N);

using namespace std;

int main()
{
    const int N=237;
	double* p=new double[N];
//	string fname="nois_filter";
	copy_txt (p, N);
//	cout<<"\n gefiltert: \n";
	filter_nois(p, N);
        file_make(p, N);
	delete_arr(p);
	
	
    return 0;
}

void copy_txt (double* p, const int N)
{
	ifstream input("noisy.txt");
	if(! input)
	{
		cout<<"die Datei wurde nicht gefunden.";
		//exit(1);
	}
	for(int i=0; i<N; i++)
	{
		if(! input.eof())
			input>> p[i];
	}
	input.close();
	/*for(int i=0; i<N; i++)
		cout<<p[i]<<endl;*/
}

void delete_arr(double* p)
{
	delete [] p ;
}

void filter_nois(double *p, int const N)
{
	double f_vor,f_curr, f_beg;
	f_vor=p[N-1];
	f_curr=p[0];
	f_beg=p[0];
	for(int i=0; i<N-1; i++)
	{
		p[i]=(f_vor+p[i]+p[i+1])/3;
		f_vor=f_curr;
		f_curr=p[i+1];

	}
	p[N-1]=(f_vor+f_curr+f_beg)/3;
	/*for(int i=0; i<N; i++)
		cout<<p[i]<<endl;*/
}
 void file_make( double *p, int const N)
 {
	 ofstream out("filtered.txt");
	 for(int i=0; i<N; i++)
	 {
		 out<<p[i]<<endl;
	 }
	 out.close();

 }
