

template<class t_Item>
struct Manager{
	t_Item** m_Array;
	int NumHeld;
	int NumMax;

	Manager(){
		nNumHeld = 0;
		NumMax = 0;
	}

	void Add(t_Item* a_Item){
		NumHeld++;
		if(NumMax == 0){
			NumMax = 10;
			m_Array = new t_Item[NumMax];
		}
		if(NumHeld == NumMax)
		{
			int Temp = NumMax*1.5;
			t_Item** TempArray = new t_Item[Temp];
			for(int i = 0;i < NumMax;i++){
				TempArray[i] = m_Array[i];
				delete m_Array[i];
			}
			m_Array = TempArray;
			NumMax = Temp;
		}
		m_Array[NumHeld] = a_Item;
	}

	t_Item* get(int Num){
		if(Num > NumMax)
			return;
		if(m_Array[Num] == NULL)
			return;
		return m_Array[Num];
	}
};