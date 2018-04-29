class DynamicArray {
public:
    // konstruktor - po umolchaniyu (sozdaem massiv nekotoroy dlinny po umolchaniyu)
    DynamicArray();

	// konstruktor - po razmeru (elementy inicializiruyutsya chislom 0)
    DynamicArray(int size);
	
	// konstruktor - po razmeru i chislu n (elementy inicializiruyutsya chislom n)
	DynamicArray(int size, int n);

    // konstruktor - kopirovaniya
    DynamicArray(const DynamicArray &other);

    // konstruktor - peremesheniya
    DynamicArray(DynamicArray &&other);

    // destruktor
    ~DynamicArray();

// metody
    // dlina massiva
    int getSize();

    // dostup k elementu (operator []) 
	int &operator[](int i);

	//izmenenie razmera
    void resize(int newSize);
	
	// operator prisvaivaniya (lvalue- ssylka na ekzemplyar etogo je klassa)
	DynamicArray &operator=(const DynamicArray &other);

    // operator peremesheniya (rvalue- ssylka na ekzemplyar etogo je klassa)
    DynamicArray &operator=(DynamicArray &&other);
	    
    bool operator==(const DynamicArray &other) const;

    bool operator!=(const DynamicArray &other) const;

    bool operator<(const DynamicArray &other) const;

    bool operator>(const DynamicArray &other) const;

    bool operator<=(const DynamicArray &other) const;

    bool operator>=(const DynamicArray &other) const;

	// konkatenaciya massivov (k tekushemu dobavlyaetsya eshe odin)
    void operator+(const DynamicArray &other);

	// operator vyvoda
    friend std::ostream &operator<<(std::ostream &os, const DynamicArray &array);

private:
	// sozdanie massiva po razmeru i chislu n (elementy inicializiruyutsya chislom n)
	void init(int size, int n);
	// ochistka
    void clear();

	// ukazatel' na dinamicheskiy massiv celyh chisel
	int *mas;
	// razmer massiva
    int size;
};
