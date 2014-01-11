

template<class t_Item>
struct Manager{
	t_Item** m_Array;
	int NumHeld;
	int NumMax;

	Manager(){
		NumHeld = 0;
		NumMax = 0;
	}

	void Add(t_Item* a_Item){
		if(NumMax == 0){
			NumMax = 10;
			m_Array = new t_Item*[NumMax];
			for(int i = 0; i < 10; i++){
				m_Array[i] = new t_Item;
			}
		}
		if(NumHeld == NumMax)
		{
			int Temp = NumMax*1.5;
			t_Item** TempArray = new t_Item*[Temp];
			for(int i = NumMax; i < Temp; i++){
				TempArray[i] = new t_Item;
			}
			for(int i = 0;i < NumMax;i++){
				TempArray[i] = m_Array[i];
			}
			m_Array = TempArray;
			NumMax = Temp;
			
		}
		delete m_Array[NumHeld];
		m_Array[NumHeld] = a_Item;
		NumHeld++;
	}

	t_Item* get(int Num){
		if(Num > NumMax)
			return;
		if(m_Array[Num] == NULL)
			return;
		return m_Array[Num];
	}

	~Manager(){
		delete[] m_Array;
	}
};