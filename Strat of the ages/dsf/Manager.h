#pragma once

template<class t_Item>
struct Manager{
	t_Item** m_Array;
	int NumHeld;
	int NumMax;

	Manager(){
		NumHeld = 0;
		NumMax = 0;
	}

	void Subtract(int a_i){
		if(NumMax == 0){
			return;
		}
		int Temp = NumMax;
		t_Item** TempArray = new t_Item*[Temp];

		for(int i = NumMax; i < Temp; i++){
			TempArray[i] = new t_Item;
		}
		delete m_Array[a_i];
		for(int i = 0;i < NumMax;i++){
			if(i < a_i)
				TempArray[i] = m_Array[i];
			else if(i > a_i)
				TempArray[i-1] = m_Array[i];
		}

		m_Array = TempArray;

		
		NumHeld--;
		if(NumHeld == 0){
			NumMax = 0;
			delete m_Array;
		}
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
			return NULL;
		if(m_Array[Num] == NULL)
			return NULL;
		return m_Array[Num];
	}

	~Manager(){
		delete[] m_Array;
	}
};