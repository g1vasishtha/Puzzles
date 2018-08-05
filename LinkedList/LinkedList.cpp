#include <iostream>

using namespace std;

class linklist
{
private:struct node
  {
    int data;
    node *link;
  } *p;

public:
linklist ()
  {
    p = nullptr;
  }
  void addafter (int c, int num);
  void appendll (int num);
  void addatBeg (int num);
  void display ();
  void del(int num);
  ~linklist();

};

void linklist::addatBeg (int num)
{
  node *q = new node;
  q->data = num;
  q->link = p;
  p = q;
}

void linklist::appendll (int num)
{
  node *q = p;
  node *t = new node;
  t->data = num;
  if (p == nullptr)
    {
      t->link = nullptr;
      p = t;
      return;
    }
  while (q->link != nullptr)
    q = q->link;

  t->link = q->link;
  q->link = t;

}

void linklist::display ()
{
  node *q = p;
  if (p == nullptr)
    {
      cout << "No Element";
      return;
    }
  while (q != nullptr)
    {
      cout << q->data << " ";
      q = q->link;
    }
    cout<<endl;
}

void linklist::addafter (int c, int num)
{
  if (c == 0)
    {
      addatBeg (num);
    }
  else
    {
      node *q;
      int i;
      for (i = 0, q = p; i < c - 1; i++, q = q->link)
	{
	  if (q == nullptr)
	    {
	      cout << "Lesser Element in LL";
	      return;
	    }
	}
      node *t = new node;
      t->data = num;
      t->link = q->link;
      q->link = t;
    }
}

void linklist :: del(int num)
{
    if(p == nullptr)
    {
        cout<<"No Element to delete"<<endl;
        return;
    }
    if( p->data == num )
    {
        node *q = p;
        p = q->link;
        delete q;
        return ;
    }
    node *q = p->link;
    node *r = p;
    while(q!=nullptr)
    {
        if(q->data == num )
        {
            r->link = q->link;
            delete q;
            return ;
        }
        r = q;
        q = q->link;
    }
    cout<<"No Such Element"<<endl;
    
}

linklist::~linklist()
{
    if(p == nullptr)
    return ;
    node * q;
    while(p!=nullptr)
    {
        q = p->link;
        delete p;
        p = q;
    }
}
int main ()
{
  linklist L;

  L.addatBeg (5);
  L.addatBeg (4);
  L.addatBeg (3);
  L.appendll (6);
  L.addatBeg (2);
  L.display ();
  L.addafter (0, 9);
  L.display ();
  L.addafter (6, 9);
  L.display ();
  L.del(9);
  L.display ();
  L.del(4);
  L.del(10);
  L.display ();
  return 0;
}
