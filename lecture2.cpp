
int x;   //Lvalues are accessible to us
x = 5; //LValue = RValue
//An Rvalue is a value that is not accessible to us in memory
//we can look back at x's location, but as 5 has no location, it is an Rvalue

int q[170]; //q is an LValue

std::cout << q+42 << std::endl; //q+42 is an Rvalue, as it is not an expressed value.
//this does not work.q is a pointer value, and cannot
//simply have an int added or subtracted from it.

std::cout << *(q+42) << std::endl; //in this example, the line works.
//in the parentheses, q is incrememnted to its 42'nd allocated block
//and then the dereference operator * accesses the data stored at that location

//////////

int a; //new int variable
int &b = a; //new int reference variable assigned to a
//in both of these lines, "a" is an LValue
int &b = 5; //nono //a reference variable, once set, cannot be changed.

const int &b = 5; //This works. The const does something idk

//////////

int sum( int a, int b ){
  return a+b;
}
int A = 1; //LValue
int B = 5; //LValue

int C = sum(A,B); //LValue = RValue;
// The returned value from a function is almost universally an Rvalue

//////////

int sum( int &a, int &b ){ //this example uses Lvalue references instead of copies
  return a+b;              //of a and b. This tells the function to look at the memory
}                          //location instead of copying the value to a new memory location
int A = 2;
int B = 4;

std::cout << sum(A,B) << std::endl; //This works.
std::cout << sum(6,7) << std::cout; //This fails. This function is expecting Lvalues.
//If you wished the make this function accept this kind of operation, ass a const to the parameters

///////////////////

void myFunction(int &x){
  std::cout << x << " is an Lvalue Reference.";
}

int f = 42;
myFunction(f);    //works.
myFunction(14);   //No LValue, does not work with Rvalues.

//what if we add the following....
void myFunction(int &&x){
  std::cout << x << " is an Rvalue reference";
} //The second function call above would work.

//What if we add this too?
void myFunction(int x) {}
// The compiler gets confused, and throws errors.

///////////////////
//Quiz 1 Post-Review

//Copy constructor
dynamicArray(const dynamicArray &other) {
  capacity = other.capacity;
  length = other.length;
  delete [] dArray;
  dArray = nullptr;
  dArray = new float[capacity];

  for (int i = 0; i < length; ++i)
    dArray[i] = other.dArray[i];

}

//Move constructor
dynamicArray(dynamicArray &&other) {
  capacity = other.capacity;
  length = other.length;
  delete [] dArray;
  dArray = other.dArray;
  delete [] other.dArray;
  other.dArray = nullptr;
}

//Copy Assignment operator
dynamicArray& operator=(const dynamicArray &other) {
  if (this != &other ) {
    capacity = other.capacity;
    length = other.length;
    delete [] dArray;
    dArray = new float[capacity];

    for (int i = 0; i < length; ++i )
      dArray[i] = other.dArray[i];
  }
  return *this;
}

//Move Assignment operator
dynamicArray& operator=(dynamicArray &&other) {
  if (this != &other ) {
    capacity = other.capacity;
    length = other.length;
    delete [] dArray;
    dArray = other.dArray;
    delete [] other.dArray;
  }
  return *this;
}

//Destructor
~dynamicArray() {
  delete [] dArray;
  dArray = nullptr;
}

////////////

void f1 ( dynamicArray d )
void f1_ref ( dynamicArray &d ) //by reference

dynamicArray createmyarray(); //function creates dyn.array object using a constructors

void main () {
  dynamicArray e = createmyarray();

  f1_ref(e); //works
  f1(e); //expensive - deep copy -> copy constructors
  f1(std::move(e)); //uses the move constructor from stl

  return 0;
}
