
/********************************************************************
*********************************************************************
*				Topic: Data Structures Project						*
*				PROTEIN STRUCTURE PREDICTION						*
*********************************************************************
*********************************************************************/


#include<iostream>
#include <algorithm> 
#include<fstream>
#include<cstring>
using namespace std;
template<typename T>
class DSA
{
	private:
		T *p=NULL;
		int size;
		public:
			DSA()
			{
				size=100;
				p=new T[100];	
					}
			DSA(const int n )
			{
				size=n;
				p=new T[n];				
			}
			DSA(const int n ,T element)
			{
				size=n;
				p=new T[n];
				memset(p,element,sizeof(T) * size)	;			
			}
			DSA(const DSA<T> &S )//copy constructor
			{
				p=new T[S.size];
				size=S.size;
				//copy(S.p,S.p+S.size,p);
				for(int i=0;i<size;i++)
				{
					*(p+i)=*(S.p+i);
								}				
			}
			T& operator[](const int x)
			{
				if(x<0||x>size)//safe array 
				{
					cout<<"Out of bound!";
					exit(1);
				}//this work can also be done in try catch block
				return p[x];
			}
			const T& operator[](const int x) const
			{
				if(x<0||x>size)//safe array 
				{
					cout<<"Out of bound!";
					exit(1);
				}//this work can also be done in try catch block
				return p[x];
			}
			void Input()
			{
				for(int i=0;i<size;i++)
				{
					cin>>p[i];
				}
			}
			void Output()
			{
				for(int i=0;i<size;i++)
				{
					cout<<p[i];
					
				}
			}
			DSA<T>& operator=(const DSA<T>& x)
			{
				T *temp=new T[x.size];
				copy(x.p,x.p+x.size,temp);
				delete[]p;
				p=temp;
				size=x.size;
				return *this;
			}
			void Resize(const int nsize)
			{
					T *ptr;
					ptr=new T [size];
					memcpy(ptr,p,sizeof(T)*size);
					delete[ ]p;
					p=0;
					size=nsize;
					p=new T[size];
					memcpy(p,ptr,sizeof(T)*size);
					delete[]ptr;
			}
			void Reverse()
			{
				T temp;
				for(int i=0,j=size-1;i<=(size/2);i++,j--)
				{
					temp=p[i];
					p[i]=p[j];
					p[j]=temp;
				}
				
			}
			friend istream& operator>>(istream & i_file, DSA<T> & rhs)
			{
				for(int i=0;i<(rhs.size);i++)
				{
					i_file>>rhs.p[i];
					if(rhs.p[i]=='\n')
					{
						rhs.size=i+1;
						break;
					}
				}
				return i_file;
			}
			friend ostream& operator<<(ostream & o_file, DSA<T> & rhs)
			{
				for(int i=0;i<(rhs.size);i++)
				{
					o_file<<rhs.p[i];
				}
				return o_file;
			}
			void operator+(T element)
			{			
				T *ptr;
				size+=1;
				ptr=new T [size];
				memcpy(ptr,p,sizeof(T)* size);
				delete[ ]p;
				p=0;
				p=new T[size];
				memcpy(p,ptr,sizeof(T)* size);
				p[size-1]=element;
				delete[]ptr;
				ptr=0;
			}
			int GetSize()
			{
				return size;
			}
			~DSA()
			{
				if(p!=0)
				{
					p=0;
				}
				delete[] p;
			}
};

template <class T>
class Double_DSA
{
	private : 
				T **data;
				int rows,cols;
	public : 
			Double_DSA()
			{
				data = 0 ; 
				rows = 0 ; 
				cols = 0 ; 	
			}
			Double_DSA(int r,int c)
			{
				rows = r;
				cols = c;
				data = new T *[rows];
					
				for(int i = 0; i < rows; i++)
				{
					data[i] = new T[cols] ;				
				}	
			}
			T& operator ()(int r,int c)
			{
				if(r>=0 && r<= rows && c>=0 && c<=cols)
				{
					return data[r][c];	
				}	
					else 
				cout<"..........";
			}
			const T& operator ()(int r,int c) const
			{
				if(r>=0 && r<= rows && c>=0 && c<=cols)
				{
					return data[r][c];	
				}	
				else 
				cout<"..........";
			}
			void display()
			{
				for(int i=0;i<rows;i++)
				{
					for(int j=0;j<cols;j++)
					{	
						cout<<data[i][j]<<"\t";
					}
					cout<<endl;		
				}	
			}
			Double_DSA (const Double_DSA &rhs)
			{
				rows = rhs.rows;
				cols = rhs.cols;
				data = new T*[rows];	
				int i,j ;
				for(i = 0 ; i < rows ; i++ )
				{
					data[i] = new T[cols];
				}
				for(i = 0; i < rows; i++)
				{																
					for(j = 0; j < cols; j++)				
					{
						data[i][j] = rhs.data[i][j];						// copying data 
					}
				}
			}
			Double_DSA& operator = (const Double_DSA& rhs)
			{
				if (this == &rhs)
       			{
      				return *this;		
				}	
				for (int i = rows-1; i >=0 ; i--)
				{
					delete data[i];
				}
				delete [] data;
	
				rows = rhs.rows;
				cols = rhs.cols;
				data = new T*[rows];
				
				int i, j ; 
				for(i = 0 ; i < rows ; i++ )
				{
					data[i] = new T[cols];
				}
				
				for(i = 0; i < rows; i++)
				{
					for(j = 0; j < cols; j++)
					{
						data[i][j] = rhs.data[i][j];	// copying data 
					}
				}				
				return *this;
			}		
};

void InputSequences(DSA<char> &sequence1,DSA<char> &sequence2,DSA<char> &sequence3,DSA<char> &sequence4,DSA<char> &sequence5,DSA<char> &sequence6)
{
	ifstream InFile;
	InFile.open("C:/Users/Aiman Siddiqui/OneDrive/SEMESTER 3 Fall 2018/DS/Project/ProteinSequences.txt");
	int i=0,size_temp;
	if(InFile.is_open())
	{
		InFile>>size_temp;
		sequence1.Resize(size_temp);
		for(i=0;i<size_temp;i++)
		{
			char temp;
			InFile>>temp;
			sequence1[i]=temp;
		}
		
		
		InFile>>size_temp;
		sequence2.Resize(size_temp);
		for(i=0;i<size_temp;i++)
		{
			char temp;
			InFile>>temp;
			sequence2[i]=temp;
		}
		
		InFile>>size_temp;
		sequence3.Resize(size_temp);
		for(i=0;i<size_temp;i++)
		{
			char temp;
			InFile>>temp;
			sequence3[i]=temp;
		}
		
		InFile>>size_temp;
		sequence4.Resize(size_temp);
		for(i=0;i<size_temp;i++)
		{
			char temp;
			InFile>>temp;
			sequence4[i]=temp;
		}
		
		InFile>>size_temp;
		sequence5.Resize(size_temp);
		for(i=0;i<size_temp;i++)
		{
			char temp;
			InFile>>temp;
			sequence5[i]=temp;
		}
		
		InFile>>size_temp;
		sequence6.Resize(size_temp);
		for(i=0;i<size_temp;i++)
		{
			char temp;
			InFile>>temp;
			sequence6[i]=temp;
		}
	}
	InFile.close();
	
}
void InputTopics(DSA<char> &sequence1,DSA<char> &sequence2,DSA<char> &sequence3,DSA<char> &sequence4,DSA<char> &sequence5,DSA<char> &sequence6,DSA<char> &sequence)
{
	ifstream InFile;
	InFile.open("C:/Users/Aiman Siddiqui/OneDrive/SEMESTER 3 Fall 2018/DS/Project/ProteinNames.txt");
	int i=0,size_temp;
	if(InFile.is_open())
	{
		InFile>>size_temp;
		sequence1.Resize(size_temp);
		for(i=0;i<size_temp;i++)
		{
			char temp;
			InFile>>temp;
			sequence1[i]=temp;
		}
		
		
		InFile>>size_temp;
		sequence2.Resize(size_temp);
		for(i=0;i<size_temp;i++)
		{
			char temp;
			InFile>>temp;
			sequence2[i]=temp;
		}
		
		InFile>>size_temp;
		sequence3.Resize(size_temp);
		for(i=0;i<size_temp;i++)
		{
			char temp;
			InFile>>temp;
			sequence3[i]=temp;
		}
		
		InFile>>size_temp;
		sequence4.Resize(size_temp);
		for(i=0;i<size_temp;i++)
		{
			char temp;
			InFile>>temp;
			sequence4[i]=temp;
		}
		
		InFile>>size_temp;
		sequence5.Resize(size_temp);
		for(i=0;i<size_temp;i++)
		{
			char temp;
			InFile>>temp;
			sequence5[i]=temp;
		}
		
		InFile>>size_temp;
		sequence6.Resize(size_temp);
		for(i=0;i<size_temp;i++)
		{
			char temp;
			InFile>>temp;
			sequence6[i]=temp;
		}

		InFile>>size_temp;
		sequence.Resize(size_temp);
		for(i=0;i<size_temp;i++)
		{
			char temp;
			InFile>>temp;
			sequence[i]=temp;
		}
	}
	InFile.close();
	
}

void InputUnknownSequence(DSA<char> &sequence)
{
	ifstream InFile;
	InFile.open("C:/Users/Aiman Siddiqui/OneDrive/SEMESTER 3 Fall 2018/DS/Project/UnknownSequence.txt");
	int i=0,size_temp;
	if(InFile.is_open())
	{
		InFile>>size_temp;
		sequence.Resize(size_temp);
		for(i=0;i<size_temp;i++)
		{
			char temp;
			InFile>>temp;
			sequence[i]=temp;
		}
	}
	InFile.close();
}

int MinValue(int a, int b, int c)
{
	if(a<=b && a<=c)
	return a;
	else if(b<=a && b<=c)
	return b;
	else
	return c;
}

float GlobalAlignmentUsingNeedlemanWunschAlgorithm(DSA<char> &sequence,DSA<char> &unknown)
{

	int SequenceCount=sequence.GetSize();
	int UnknownCount=unknown.GetSize() ;
	const int GapPenalty=2 ;
	Double_DSA<int> ScoreMatrix(UnknownCount+1,SequenceCount+1);
	
	//initializing the scoreboard
	for (int i=0; i<=SequenceCount; ++i)
	{
    	ScoreMatrix(0,i)=i*GapPenalty;
	}	

	for (int j=0; j<=UnknownCount; ++j)
	{
    	ScoreMatrix(j,0)=j*GapPenalty;
	} 


	int alphabets[26][26];
    for (int i=0; i<26; ++i)
    {
        for (int j=0; j<26; ++j)
        {
            if (i==j) 
			alphabets[i][j] = 0;
            else 
			alphabets[i][j] = 1;
        }
    }
    
    //matrix filling
	int Score1=0,Score2=0,Score3=0;
	char element_seq,element_unknown;
	for(int i=1; i<=UnknownCount; ++i)
	{
		for (int j=1; j<=SequenceCount; ++j)
		{
			//score of diagnonal one
			element_seq=sequence[j-1];
			element_unknown=unknown[i-1];
			Score1=ScoreMatrix(i-1,j-1)+alphabets[element_seq-'A'][element_unknown-'A'];
				
			//score of left one	
			Score2=ScoreMatrix(i,j-1)+GapPenalty;
			
			//score of UP one
			Score3=ScoreMatrix(i-1,j)+GapPenalty;
			//minimum score being saved on the matrix
			ScoreMatrix(i,j)=MinValue(Score1,Score2,Score3);
		
		}
	}
	
	cout<<endl;
	char a=' ';
	char element_a,element_b;
	DSA<char> AlignedSeq(1,a);
	DSA<char> AlignedUnknown(1,a);
	
	int j= SequenceCount, i= UnknownCount ;

	for(;i>=1 && j>=1;)
	{
		element_a=sequence[j-1];
		element_b=unknown[i-1];
		if(ScoreMatrix(i,j)==(ScoreMatrix(i-1,j-1)+alphabets[element_b- 'A'][element_a - 'A']))
		{
			AlignedSeq + element_a;
			AlignedUnknown + element_b;
			--j;
			--i;
		}
		else if(ScoreMatrix(i,j) == (ScoreMatrix(i-1,j) + GapPenalty))
		{
			AlignedSeq + element_a;
			a='-';
			AlignedUnknown + a;
			--i;
		}
		else// if(ScoreMatrix(i,j) == (ScoreMatrix(i,j-1) + GapPenalty))
		{
			a='-';
			AlignedSeq + a;
			AlignedUnknown + element_b;
			--j;
			--i;
		}
	}
	 while (i>0 && j<1)
    {
    	a='-';
		AlignedSeq + a;
		a=unknown[i-1];
		AlignedUnknown + a;
		--i;
		
    }
    while (j>0 && i<1)
    {
    	a= sequence[j-1];
        AlignedUnknown + a;
		a='-';
		AlignedSeq + a;
        --j; 
    }
    cout<<endl<<"---------------------KNOWN SEQUENCE------------------"<<endl;
	AlignedSeq.Reverse();
	AlignedSeq.Output();
	cout<<endl;
	cout<<endl<<"---------------------UNKNOWN SEQUENCE------------------"<<endl;
	AlignedUnknown.Reverse();
	AlignedUnknown.Output();
	cout<<endl<<"SCORE:"<<ScoreMatrix(UnknownCount,SequenceCount)<<endl;
	cout<<"============================================================="<<endl;
	return ScoreMatrix(UnknownCount,SequenceCount);
}
int main()
{
	float score[6],unmatched,percent[6];
	DSA<char> seq1,seq2,seq3,seq4,seq5,seq6,unknown;
	DSA<char> Topicseq1,Topicseq2,Topicseq3,Topicseq4,Topicseq5,Topicseq6,Topicunknown;
	InputTopics(Topicseq1,Topicseq2,Topicseq3,Topicseq4,Topicseq5,Topicseq6,Topicunknown);
	InputSequences(seq1,seq2,seq3,seq4,seq5,seq6);
	InputUnknownSequence(unknown);
	char a=' ';
	DSA<char> empty(1,a);
	unmatched=GlobalAlignmentUsingNeedlemanWunschAlgorithm(empty,unknown);
	cout<<endl<<endl;
	system("cls");
	cout<<"============================================================="<<endl;
	cout<<"======================SEQUENCE NO 1=========================="<<endl;
	cout<<"============================================================="<<endl;
	score[0]=GlobalAlignmentUsingNeedlemanWunschAlgorithm(seq1,unknown);
	cout<<endl<<endl;
	cout<<"============================================================="<<endl;
	cout<<"======================SEQUENCE NO 2=========================="<<endl;
	cout<<"============================================================="<<endl;
	score[1]=GlobalAlignmentUsingNeedlemanWunschAlgorithm(seq2,unknown);
	cout<<endl<<endl;
	cout<<"============================================================="<<endl;
	cout<<"======================SEQUENCE NO 3=========================="<<endl;
	cout<<"============================================================="<<endl;
	score[2]=GlobalAlignmentUsingNeedlemanWunschAlgorithm(seq3,unknown);
	cout<<endl<<endl;
	cout<<"============================================================="<<endl;
	cout<<"======================SEQUENCE NO 4=========================="<<endl;
	cout<<"============================================================="<<endl;
	score[3]=GlobalAlignmentUsingNeedlemanWunschAlgorithm(seq4,unknown);
	cout<<endl<<endl;
	cout<<"============================================================="<<endl;
	cout<<"======================SEQUENCE NO 5=========================="<<endl;
	cout<<"============================================================="<<endl;
	score[4]=GlobalAlignmentUsingNeedlemanWunschAlgorithm(seq5,unknown);
	cout<<endl<<endl;
	cout<<"============================================================="<<endl;
	cout<<"======================SEQUENCE NO 6=========================="<<endl;
	cout<<"============================================================="<<endl;
	score[5]=GlobalAlignmentUsingNeedlemanWunschAlgorithm(seq6,unknown);
	
	for(int i=0;i<6;i++)
	{
		score[i]=unmatched-score[i];
		percent[i]=(score[i]*100)/unmatched;
		//cout<<percent[i]<<endl;
	}
	cout<<"============================================================="<<endl;
	cout<<"================PERCENTAGE SIMILARITIES======================"<<endl;
	cout<<"============================================================="<<endl;
	cout<<"1.";
	Topicseq1.Output();
	cout<<"\t\t\t"<<percent[0]<<"%"<<endl<<endl;
	
	cout<<"2.";
	Topicseq2.Output();
	cout<<"\t"<<percent[1]<<"%"<<endl<<endl;
	
	cout<<"3.";
	Topicseq3.Output();
	cout<<"\t\t\t"<<percent[2]<<"%"<<endl<<endl;
	
	cout<<"4.";
	Topicseq4.Output();
	cout<<"\t\t\t"<<percent[3]<<"%"<<endl<<endl;
	
	cout<<"5.";
	Topicseq5.Output();
	cout<<"\t\t\t"<<percent[4]<<"%"<<endl<<endl;
	
	cout<<"6.";
	Topicseq6.Output();
	cout<<"\t\t\t\t"<<percent[5]<<"%"<<endl<<endl;
}
