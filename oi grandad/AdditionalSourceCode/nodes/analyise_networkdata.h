namespace project
{

struct analyise_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "analyise";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "497.nT6K8CF4CzyC.XjUGUB7Nq9CvRq+29eX3kvJr89dXmsXKNRyKvFRhrIkKdyfqAhImlTF6.PO.rC.SL.qh4bb81GGzItjld70eTdwGr5Deu4yT9W8knUcLolcUoItwpQ4ia5cTm68A1wlcrpELPqRwTZw6ZR7kwiiEwvcQ9v5nzeawiC2zjUzrn+.GvpdGr6jgY7Ye+z2jyMQqDTNWX5bVN7IAaPBOrmFOPzpJGz5ZsFMuuSNYFl9+lVX0eiY8QuBmQP4FNLh9xB1QHgYbAqhg4xiQYk2ylMDQ46aXmN8205YuQ0pIPnpjDgEvS2C6ZIbK61QJTYbCnUqfLgJxDIUOhvDr5rSBkUTfo9VS9cTlllpdPwNhzWB4Pcwiyl+bZfhYHMwLuJztqTVLPEnA1xTHXJDl.VbPM.P..HkNePMH.YcGPgCAnluNgMNRjGtjPh8T.Y2V7jdUwNtfDO5zEOyNdJ6nMNlMiMYRUXbv1JoVq8dGOvyNIZzpxvGFxuLDA7mfSM08DrfP.2T9ASjnY5gxbH9OHcKWX0r6Gpd9OXj7FIQ9vL8E0h9CPGOfQt3LV1VCgXym.N5.wI3IOnaW.hPggFyFmz6amQOtJAQ4hWO6IEGEBsZFb3boLpzFKyoL87ChPY4kQq.wGY4z065.UGfuJ.";
	}
};
}

