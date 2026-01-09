//
// Created by ferida on 9/1/25.
//
//in python we have string objects, but in C we have arrays of chars of fixed sizes
//below we emulate the string object in python, using C

#include <stdio.h>
#include <stdlib.h>

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





/* x = x + 'h'; */
void pystr_append(struct pystr* self, char ch) {
    /* Need about 10 lines of code here */
    //loop through the list until I reach the NUll
    //keep track of how many nodes were passed
    self->length = 0;
    self->alloc = 10;
    int index = 0;
    while(self->data[index] != '\0'){
        index++;
        (self->length)++;//we're getting the length of the string that is currently present within data array
    }

    //check if length of string + 1 (to account for the null terminator) is greater than self-alloc
    if ((self->length)+1 >= self->alloc) {
        self->data = realloc(self->data, self->alloc + 10);//then add 10 more bytes of memory
        self->alloc = self->alloc + 10; //increment self->alloc
    }
    self->data[self->length] = ch; //set that position equal to the character
    self->data[++self->length] = '\0';//add the null terminator


}

/* x = x + "hello"; */
void pystr_appends(struct pystr* self, char *str) {
    /* Need a line or two of code here */
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        pystr_append(self, str[i]);
    }
}

/* x = "hello"; */
void pystr_assign(struct pystr* self, char *str) {
    /* Need about three lines of code here */
    //replace the contents of self->data with str

    free(self->data);//start by clearing all previous data
    self->data = malloc(10);
    self->data[0] = '\0';
    pystr_appends(self, str);

}







/* Destructor - del(x) */
void pystr_del(const struct pystr* self) {
    free((void *)self->data); /* free string first */
    free((void *)self);
}

void pystr_dump(const struct pystr* self)
{
    printf("Pystr length=%d alloc=%d data=%s\n",
            self->length, self->alloc, self->data);
}

int pystr_len(const struct pystr* self)
{
    return self->length;
}

char *pystr_str(const struct pystr* self) //returns the ptr to the string
{
    return self->data;
}


int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);  /* Internal */

    struct pystr * x = pystr_new(); //create a string object
    pystr_dump(x);//print it out

    pystr_append(x, 'H');//append an H to it
    pystr_dump(x);

    pystr_appends(x, "ello world");//append each char of this string to it
    pystr_dump(x);

    pystr_assign(x, "A completely new string");//change the existing string to this
    printf("String = %s\n", pystr_str(x));
    printf("Length = %d\n", pystr_len(x));
    pystr_del(x);
}