template <typename T>
class Vector{

    private:
        T* elements;
        unsigned size;
        unsigned capacity;
        const unsigned enlargement = 10;

        void setSize(unsigned s){
            size = s;
        }

        void setCapacity(unsigned c){
            capacity = c;
        }

    public:

        Vector(){
            elements = new T[1];
            size = 0;
            capacity = 1;
        }

        T* getElements() const{
            return elements;
        }

        unsigned getSize() const{
            return size;
        }

        unsigned getCapacity() const{
            return capacity;  
        }

        void push(const T& element){
            if(getSize() >= getCapacity()){
                T* newElements = new T[getSize() + enlargement];

                setCapacity(getCapacity()+enlargement);

                for(int i = 0; i < getSize(); i++)
                    newElements[i] = elements[i];

                delete []elements;
                elements = newElements;
            }
            elements[getSize()] = element;
            setSize(getSize()++);
        }

        void remove(){
            if(size > 0) {
                size--;
                return;
            }
            throw "Can not remove from empty vector";
        }

        void removeSubarray(int a, int b){
            if(a < 0 || a >= size || b < 0 || b >= size) throw "Illegal indexes for subarray";
            //
        }


        ~Vector(){
            delete []elements;
        }

};