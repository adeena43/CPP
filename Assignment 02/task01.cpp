#include<iostream>
#include<string>
using namespace std;

class SecurityTool{
	protected:
		string securityLevel;
		double cost;
		int numberOfDevices;
	public:
		SecurityTool(string securityLevel, double cost, int num)
		{
			if(securityLevel=="High"||securityLevel=="Medium"||securityLevel=="Low")
			{
				this->securityLevel=securityLevel;
			}
			else
			{
				perror("Invalid security level, setting it to Low");
							}
			
			if(cost>0)
			{
				this->cost=cost;
			}
			
			else
			{
				perror("Invalid cost");
			}
		}
		
		void performScan()
		{
			cout<<"Performimg a generic security scan"<<endl;
		}
};

class FirewallTool:protected SecurityTool{
	private:
		int ports[24];
		string protocols[6];
		
	public:
		FirewallTool(string secLevel, double toolCost,int num, int ID):SecurityTool(secLevel,toolCost,num )
		{
			int initial = (ID%10)+4;
		int i;
		for(i = 0; i<23;i++)
		{
			ports[i]=initial+i;
		}
		
		protocols[0]="HTTPS";
		protocols[1]="FTP";
		protocols[2]="UDP";
		protocols[3]="ICMP";
		protocols[4]="SSH";
		protocols[5]="SNMP";
		}
		
		
		
		void generateList()
		{
			cout<<"Allowed ports: "<<endl;
			for(int i =0;i<23;i++)
			{
				cout<<ports[i]<<"\t";
			}
			cout<<endl;
		}
		
		void performScan(){
		
		cout << "Performing firewall scan..." << endl;
        if (securityLevel == "High") {
            cout << "Only traffic from allowed ports and protocols are allowed." << endl;
        } else if (securityLevel == "Medium") {
            cout << "All traffic from allowed ports and protocols are allowed, along with next two ports in sequence." << endl;
            cout << "Next two ports: " << ports[22] + 1 << " " << ports[22] + 2 << endl;
        } else { // Low
            cout << "All traffic from allowed ports and protocols are allowed, along with the next 5 ports in sequence and from TCP and DNS protocols." << endl;
            cout << "Next five ports: ";
            for (int i = 0; i < 5; ++i) {
                cout << ports[22] + i + 1 << " ";
            }
            cout << endl;
            cout << "Additional protocols: TCP, DNS" << endl;
        }
    }
};

int main()
{
	cout<<"Adina Faraz"<<endl<<"23k-0008"<<endl;
	FirewallTool firewall("High", 100.0, 10, 12345); // Assuming student ID is 12345
    firewall.performScan();
    firewall.generateList();

    return 0;
}
