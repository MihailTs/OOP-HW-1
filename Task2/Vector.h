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

        void setElements(T* _elements){
            elements = _elements;
        }

        unsigned getCapacity() const{
            return capacity;  
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
            setSize(getSize()+1);
        }

        void remove(){
            if(size > 0) {
                size--;
                return;
            }
            throw "Can not remove from empty vector";
        }

        void removeSubarray(int start, int end){
            if(start < 0 || start >= getSize() || end < 0 || end >= getSize() || start > end) throw "Illegal indexes for subarray";
            
            T* newElements = new T[getSize() - (end-start) - 1];
            int i;
            for(i = 0; i < start; i++)
                newElements[i] = getElements()[i];
            
            for(int j = end+1; j < getSize(); j++)
                newElements[i++] = getElements()[j];

            setSize(getSize() - (end-start) - 1);
            delete []getElements();
            setElements(newElements);
        }

        T operator[](int i) const{
            if(i < 0 || i > getSize()) throw "Index out of bounds";
            return getElements()[i];
        }

        bool isTrueForAll(bool(*predicate)(T)){
            for(int i = 0; i < getSize(); i++)
                if(!predicate(getElements()[i])) return false;
            return true;
        }

        Vector operator+(const Vector& v){
            Vector newVector;
            for(int i = 0; i < getSize(); i++)
                newVector.push(getElements()[i]);

            for(int i = 0; i < v.getSize(); i++)
                newVector.push(v[i]);

            return newVector;
        }

        void map(T(*fn)(T)){
            T* newElements = new T[getSize()];
            for(int i = 0; i < getSize(); i++)
                newElements[i] = fn(getElements()[i]);
            
            delete []getElements();
            setElements(newElements);
        }

        Vector getSubarray(int start, int end){
            Vector v;
            for(int i = start; i <= end; i++)
                v.push(getElements()[i]);
            return v;
        }

        ~Vector(){
            delete []elements;
        }

};