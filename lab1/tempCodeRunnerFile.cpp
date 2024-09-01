#include<iostream>
using namespace std;

class Document{
    string *text;

    public:
    Document(){};

    void settext(string txt){
        text = new string(txt);
    }

    Document(string data){
        text = new string(data);
    }

    ~Document(){
        delete text;
    }

    Document(Document &doc2){
        text = new string(*doc2.text);      //Deep copy
    }

    Document& operator= (Document &doc2) {
        text = new string(*doc2.text);      //assignment operator
        return *this;
    }

    void print(){
        cout<<"The text of document is: "<<*text<<endl;
    }
};


int main()
{
    Document doc1("Rayyan ur rehman");
    Document doc2 = doc1; 
    Document doc3("sufyan ur rehman");
    doc3 = doc1;

    doc1.print();
    doc2.print();
    doc3.print();
    
    doc1.settext("azlaan ur rehman");       //checking after modifying original document.

    doc1.print();
    doc2.print();
    doc3.print();

    return 0;
} 