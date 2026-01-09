//
// Created by ferida on 9/9/25.
//

//each new string will have the following attributes (attributes are listed in the struct)
struct pystr
{
    int length; //the number of chars in the string
    int alloc; /* the length of *data - how much memory will be allocated */
    char *data; //data is a ptr to char - stores memory address of a char
};

/* Constructor - x = str() */
struct pystr * pystr_new() { //aka a 'method' in python - points to a new struct pystr each time it is called

    struct pystr *p = malloc(sizeof(*p)); //allocate memory for a new struct
    p->length = 0;//set size of string to 0 at first
    p->alloc = 10; //we will allocate 10 bytes of memory for our new string object - this variable will be useful later

    p->data = malloc(10); //allocate 10 chars of memory
    p->data[0] = '\0'; //make it an empty string - unlike python, strings in C end with NULL character
    return p;

}
//use realloc to expand the buffer by 10 if storage is exceeded





//to add one char
/* x = x + 'h'; */
void pystr_append(struct pystr* self, char ch) {

    if (self->length >= self->alloc) {
        self->data = realloc(self->data, self->alloc *= 2);
        self->alloc *= 2;
    }
    char *cur = self->data; //self->data refers to teh first element of the array in C
    while (*cur != '\0') {//must dereference for char in the memory address
        cur++;
    }

    *cur = ch;
    *(++cur) = '\0';
    self->length++;
}

//to add a string
/* x = x + "hello"; */
void pystr_appends(struct pystr* self, char *str) {
    /* Need a line or two of code here */
    //get to the end of the string, and append each letter to the end



}

//to change a string entirely
/* x = "hello"; */
void pystr_assign(struct pystr* self, char *str) {
    /* Need about three lines of code here */
    //replace the contents of self->data with str


}
