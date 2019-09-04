#include <iostream>
using namespace std;
class PP
{   char c;
public:
	PP(char cc='A') {c=cc; }
	void show( );
	void show( )const;	
};
void PP::show( )
{   cout<<c<<"@"; }
void PP::show( ) const
{   cout<<c<<"!"; }
int main()
{   PP p1('B');
	const PP p2('S');
	p1.show();
	p2.show();
	cout<<endl;
	return 0;
}
