/*
Name-> Adina faraz
student ID-> 23k-0008
*/

#include<iostream>
#include<cstdlib>
using namespace std;

class Image{
	private:
		int width;
		int height;
		int* imgData;
		
	public:
		Image(double w, double h, int* data)
		{
			this->width = w;
			this->height =h;
			
			int size = width*height;
			imgData = new int[size];
			for(int i =0; i<size; i++)
			{
				imgData[i] = data[i];
			}
		}
		
		//copy constructor
		Image(Image& obj2)
		{
			this->width = obj2.width;
			this->height = obj2.height;
			
			int size = width*height;
			imgData = new int[size];
			
			for(int i =0; i<size; i++)
			{
				imgData[i] = obj2.imgData[i];			}
		}
		
		~Image()
		{
			delete []imgData;
		}
		
		void display()
		{
			cout<<"Image Data: "<<endl;
			for(int i =0; i<width*height; i++)
			{
				cout<<imgData[i]<<"\t";
				if((i+1)%width==0)
				{
					cout<<endl;
				}
			}
		}
		
		void updateData()
		{
			for(int i =0; i<width*height; i++)
			{
				if(imgData[i]<=0)
				{
					imgData[i]=rand()%255+1;
				}
			}
		}
};

int main()
{
	int imgData[] = {1,2,66,78};
	Image original(2,3 ,imgData);
	Image copy = original;
	
	cout<<"Original Image: "<<endl;
	original.display();
	
	cout<<"Copied image: "<<endl;
	copy.display();
	
	original.updateData();
	cout<<"Updated original image data:"<<endl;
	original.display();
	
	cout<<"Updated copy image data:"<<endl;
	copy.display();
	
	return 0;
}
