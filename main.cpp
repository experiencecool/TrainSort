#include <stdio.h>
#include <iostream>
#include <fstream>
#include <climits>
#include <cstdlib>

using namespace std;

struct lifo {
	int data;
	lifo *next;

};

void s_push(int d, lifo *&mylist) { // link on address whaaat?
	lifo *temp = new lifo;
	temp->data = d;
	temp->next = mylist->next;
	mylist->next = temp;
}

int s_take(lifo *mylist){
    lifo *temp = mylist->next;
    int d;

    if(temp == NULL) {
        cout << "there is so... empty... here...\n";
        //throw "0x001";
    }
    else {

        d = temp->data;
        mylist->next = temp->next;
        delete temp;
    }


    return d;
}

bool is_s_empty(lifo *mylist)
{
    if(mylist->next == NULL) return true;
    else return false;
}


int main() {
    lifo *f_rail = new lifo; ///in "class" it would be "initialization
    f_rail->next = NULL;

    lifo *s_rail = new lifo;
    s_rail->next = NULL;

    lifo *t_rail = new lifo;
    t_rail->next = NULL;

    ifstream in("in.txt");
    ofstream fout("out.txt");
    int n;
    in >> n;

    for(unsigned register int i = 0; i < n; i++)
    {
        int temp;
        in >> temp;
        s_push(temp, f_rail);
    }


    int tn = -1 , k = 0;
    //int min_n = INT_MAX;
    bool p = true;

    while(p)
    {
        int min_n = INT_MAX;
        int temp;
        for(int i = 0; i < n; i++)
        {
            temp = s_take(f_rail);
            cout << temp  << " ^1 "<< endl;
            if(temp < min_n){
                min_n = temp;
                tn = n-i-1;
                cout << "remembered " << tn << endl;
            }
            s_push(temp, s_rail);
            cout << temp  << " !2 "<< endl;
        }
        cout << endl;

        for(int i = 0; i < n; i++)
        {
            temp = s_take(s_rail);
            cout << temp  << " ^2 "<< endl;

            if( i == tn ){
                s_push(temp, t_rail);
                cout << temp  << " !3 "<< endl;
            }
            else {
                s_push(temp, f_rail);
                cout << temp  << " !1 "<< endl;
            }
        }
        n--;

        cout << endl;
		

        if(is_s_empty(f_rail) && is_s_empty(s_rail)) p = false;
      //  if(k = 1000) p = false;
        //k++;
    }

    for(unsigned register int i = 0; i < n; i++)
    {
        fout << s_take(t_rail) << " ";
    }
	system("pause");
	return 0;
}
