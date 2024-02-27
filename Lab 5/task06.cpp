#include<iostream>
using namespace std;
class GraphicsRenderingEngine{
	public:
		void render()
		{
			cout<<"Rendering engine in process"<<endl;
		}
};
class InputHandler{
	public:
		void inputHandler()
		{
			cout<<"Input Handling in process"<<endl;
		}
};
class PhysicsEngine{
	public:
		void physicsEngine()
		{
			cout<<"Simulating Physics"<<endl;
		}
};

//main class/ base class
class GameEngine{
	private:
		GraphicsRenderingEngine gre;
		InputHandler IH;
		PhysicsEngine PE;
	public:
		GameEngine()
		{
			cout<<"---------GAME ENGINE----------"<<endl;	
		}
		
		void startEngine()
		{
			gre.render();
			IH.inputHandler();
			PE.physicsEngine();
		}
};
int main()
{
	cout<<"Adina Faraz"<<endl<<"23k-0008"<<endl;
	GameEngine G1;
	G1.startEngine();
}
