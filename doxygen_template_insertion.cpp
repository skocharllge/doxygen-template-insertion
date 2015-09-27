//Author Srinivas Kocharlakota Doxygen Parser
#include <iostream>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <vector>
#include <regex>
#include <fstream>
#include <unordered_map>
#include <string>
#include <string.h>
#include <unordered_set>
using namespace std;
//forward declaration
class DoxygenContext;
class DoxygenLEFTBRACEState;

/**************************************************************
 * State implementation for DoxygenDoxygenState
 **************************************************************/
class DoxygenDoxygenState
{
public:
	DoxygenDoxygenState();

	~DoxygenDoxygenState();

	// OnEntry
	virtual void OnEntry(DoxygenContext &context) ;
	// OnExit
	virtual void OnExit(DoxygenContext &context) ;
	// Events implementation for state  DoxygenDoxygenState
	virtual void doxygen_c_plus_plus_comment(DoxygenContext &context) ;
	virtual void doxygen_page_tag(DoxygenContext &context) ;
	virtual void doxygen_left_brace_tag(DoxygenContext &context) ;
	virtual void doxygen_section_tag(DoxygenContext &context) ;
	virtual void doxygen_par_parameters_tag(DoxygenContext &context) ;
	virtual void doxygen_right_brace_tag(DoxygenContext &context) ;
	virtual void doxygen_end_c_plus_plus_comment(DoxygenContext &context);
	virtual void doxygen_ls_tag(DoxygenContext &context);

};

class DoxygenContext
{
public:
	DoxygenContext()
	{
		current = new DoxygenDoxygenState();

	}
	~DoxygenContext()
	{

	}
	virtual void doAction()
	{
	}
	void setCurrentState(DoxygenDoxygenState *s)
	{
		current = s;
	}
	DoxygenDoxygenState *getCurrentState()
	{
		return current;
	}
	// OnEntry
	virtual void OnEntry()
	{
		current->OnEntry(*this);
	}
	// OnExit
	virtual void OnExit()
	{
		current->OnExit(*this);
	}
	// Events implementation for state  DoxygenDoxygenState
	virtual void doxygen_c_plus_plus_comment()
	{
		current->doxygen_c_plus_plus_comment(*this);
	}
	virtual void doxygen_page_tag()
	{
		current->doxygen_page_tag(*this);
	}
	virtual void doxygen_left_brace_tag()
	{
		current->doxygen_left_brace_tag(*this);
	}
	virtual void doxygen_section_tag()
	{
		current->doxygen_section_tag(*this);
	}
	virtual void doxygen_par_parameters_tag()
	{
		current->doxygen_par_parameters_tag(*this);
	}
	virtual void doxygen_right_brace_tag()
	{
		current->doxygen_right_brace_tag(*this);
	}
	virtual void doxygen_end_c_plus_plus_comment()
	{
		current->doxygen_end_c_plus_plus_comment(*this);
	}
	virtual void doxygen_ls_tag()
	{
		current->doxygen_ls_tag(*this);
	}

	DoxygenDoxygenState *current;
	std::ofstream *filep;
	string template_file;



};

// State Constructor
DoxygenDoxygenState::DoxygenDoxygenState()
{
	//  printf("%s\n",__FUNCTION__);
}

// State Destructor
DoxygenDoxygenState::~DoxygenDoxygenState()
{

}

// OnEntry
void DoxygenDoxygenState::OnEntry(DoxygenContext &context)
{
	// OnEntry for state DoxygenDoxygenState


}

// OnExit
void DoxygenDoxygenState::OnExit(DoxygenContext &context)
{

}

// Events implementation for state  DoxygenDoxygenState
void DoxygenDoxygenState::doxygen_c_plus_plus_comment(DoxygenContext &context)
{
	// 0 transition(s)

}

void DoxygenDoxygenState::doxygen_page_tag(DoxygenContext &context)
{
	// 0 transition(s)

}

void DoxygenDoxygenState::doxygen_left_brace_tag(DoxygenContext &context)
{
	// 0 transition(s)

}

void DoxygenDoxygenState::doxygen_section_tag(DoxygenContext &context)
{
	// 0 transition(s)

}

void DoxygenDoxygenState::doxygen_par_parameters_tag(DoxygenContext &context)
{
	// 0 transition(s)

}

void DoxygenDoxygenState::doxygen_right_brace_tag(DoxygenContext &context)
{
	// 0 transition(s)

}

void DoxygenDoxygenState::doxygen_end_c_plus_plus_comment(
    DoxygenContext &context)
{
	// 0 transition(s)

	printf("\n\n");
}
void DoxygenDoxygenState::doxygen_ls_tag(DoxygenContext &context)
{

}
class DoxygenENDBASEState;
/**************************************************************
 * State implementation for DoxygenIDLEState
 **************************************************************/

// State Constructor
class DoxygenIDLEState: public DoxygenDoxygenState
{
public:
	DoxygenIDLEState() : DoxygenDoxygenState()
	{
		printf("DoxygenIDLEState constructor\n");
	}

	// State Destructor
	~DoxygenIDLEState()
	{
	}


	// OnEntry
	void OnEntry(DoxygenContext &context)
	{
		printf("[DoxygenIDLEState]%s\n", __FUNCTION__);
	}

	// OnExit
	void OnExit(DoxygenContext &context)
	{
		printf("[DoxygenIDLEState]%s\n", __FUNCTION__);
	}

	// Events implementation for state  DoxygenIDLEState
	void doxygen_c_plus_plus_comment(DoxygenContext &context) ;

	void doxygen_end_c_plus_plus_comment(DoxygenContext &context)
	{
		printf("[DoxygenIDLEState]%s\n", __FUNCTION__);
		context.setCurrentState(this);

	}
	void doxygen_page_tag(DoxygenContext &context);
	void doxygen_ls_tag(DoxygenContext &context)
	{

		std::ifstream ifs(context.template_file);
		std::string content((std::istreambuf_iterator<char>(ifs)),
		                    (std::istreambuf_iterator<char>()));
		*(context.filep) << content;

	}

};

/**************************************************************
 * State implementation for DoxygenENDState
 **************************************************************/
class DoxygenENDState: public DoxygenDoxygenState
{
public:
	// State Constructor
	DoxygenENDState() : DoxygenDoxygenState()
	{

	}

	// State Destructor
	~DoxygenENDState()
	{
	}


	// OnEntry
	void OnEntry(DoxygenContext &context) const
	{
		// OnEntry for state DoxygenENDState

	}

	// OnExit
	void OnExit(DoxygenContext &context) const
	{
		// OnExit for state DoxygenENDState

	}
	void doxygen_end_c_plus_plus_comment(DoxygenContext &context)
	{
		printf("[DoxygenENDState]In %s\n", __FUNCTION__);
		auto temp = context.current;
		context.setCurrentState((DoxygenDoxygenState *)new DoxygenIDLEState());

		if (temp)
		{
			free(temp);
		}


	}
	void doxygen_c_plus_plus_comment(DoxygenContext &context)
	{
		printf("[DoxygenENDState]In %s\n", __FUNCTION__);
		auto temp = context.current;
		context.setCurrentState((DoxygenDoxygenState *)new DoxygenIDLEState());

		if (temp)
		{
			free(temp);
		}

	}
};

/**************************************************************
 * State implementation for DoxygenENDBASEState
 **************************************************************/
class DoxygenENDBASEState: public DoxygenDoxygenState
{
public:
	// State Constructor
	DoxygenENDBASEState() : DoxygenDoxygenState()
	{

	}
	~DoxygenENDBASEState()
	{
	}
	void doxygen_end_c_plus_plus_comment(DoxygenContext &context)
	{
		printf("[DoxygenENDBASEState]%s\n", __FUNCTION__);
		auto temp = context.current;
		context.setCurrentState((DoxygenDoxygenState *)new DoxygenENDState());

		if (temp)
		{
			free(temp);
		}
	}
	void doxygen_c_plus_plus_comment(DoxygenContext &context)
	{
		printf("[DoxygenENDBASEState]%s\n", __FUNCTION__);
		auto temp = context.current;
		context.setCurrentState((DoxygenDoxygenState *)new DoxygenIDLEState());

		if (temp)
		{
			free(temp);
		}
	}
};
/**************************************************************
 * State implementation for DoxygenPARAMETERSState
 **************************************************************/
class DoxygenPARAMETERSState: public DoxygenDoxygenState
{
public:
	// State Constructor
	DoxygenPARAMETERSState() : DoxygenDoxygenState()
	{

	}

	// State Destructor
	~DoxygenPARAMETERSState()
	{
	}

	void doxygen_c_plus_plus_comment(DoxygenContext &context)
	{
		printf("[DoxygenENDBASEState]%s\n", __FUNCTION__);
		auto temp = context.current;
		context.setCurrentState((DoxygenDoxygenState *)new DoxygenIDLEState());

		if (temp)
		{
			free(temp);
		}
	}
	// OnEntry
	void OnEntry(DoxygenContext &context) const
	{
		// OnEntry for state DoxygenPARAMETERSState

	}

	// OnExit
	void OnExit(DoxygenContext &context) const
	{
		// OnExit for state DoxygenPARAMETERSState

	}

	void doxygen_par_parameters_tag(DoxygenContext &context)
	{
		// 1 transition(s)
		printf("[DoxygenPARAMETERSState]%s\n", __FUNCTION__);
		auto temp = context.current;
		context.setCurrentState((DoxygenDoxygenState *)new DoxygenPARAMETERSState());

		if (temp)
		{
			free(temp);
		}



	}
	void doxygen_right_brace_tag(DoxygenContext &context)
	{
		// 1 transition(s)
		printf("[DoxygenPARAMETERSState]%s\n", __FUNCTION__);
		auto temp = context.current;
		context.setCurrentState((DoxygenDoxygenState *)new DoxygenENDBASEState());

		if (temp)
		{
			free(temp);
		}
	}


};
/**************************************************************
 * State implementation for DoxygenSECTIONState
 **************************************************************/
class DoxygenSECTIONState: public DoxygenDoxygenState
{
public:
	// State Constructorsensp
	DoxygenSECTIONState() : DoxygenDoxygenState()
	{

	}

	// State Destructor
	~DoxygenSECTIONState()
	{
	}

	// OnEntry
	void OnEntry(DoxygenContext &context)
	{
		// OnEntry for state DoxygenSECTIONState

	}

	// OnExit
	void OnExit(DoxygenContext &context)
	{
		// OnExit for state DoxygenSECTIONState

	}

	// Events implementation for state  DoxygenSECTIONState
	void doxygen_par_parameters_tag(DoxygenContext &context)
	{
		// 1 transition(s)
		printf("[DoxygenSECTIONState]%s\n", __FUNCTION__);
		auto temp = context.current;
		context.setCurrentState((DoxygenDoxygenState *)new DoxygenPARAMETERSState());

		if (temp)
		{
			free(temp);
		}

	}
	// Events implementation for state  DoxygenSECTIONState
	void doxygen_end_c_plus_plus_comment(DoxygenContext &context)
	{
		// 1 transition(s)

		*(context.filep) << "@par Parameters\n";

		*(context.filep) << " Name | Required | Type | Description\n";
		*(context.filep) << "-----|--------|------|----------\n";

		*(context.filep) << "@par Returns(Call)\n";

		*(context.filep) << "Name | Required | Type | Description\n";
		*(context.filep) << "-----|--------|------|----------\n";
		*(context.filep) <<
		                 "returnValue | yes | Boolean | True, when operation was successfull. False otherwise.\n";

		*(context.filep) << "@par Returns(Subscription)\n";

		*(context.filep) << "Not applicable.\n";

		*(context.filep) << "@}";
		auto temp = context.current;
		context.setCurrentState((DoxygenDoxygenState *)new DoxygenENDState());

		if (temp)
		{
			free(temp);
		}



	}


};


/**************************************************************
 * State implementation for DoxygenSTARTBASEState
 **************************************************************/
class DoxygenSTARTBASEState: public DoxygenDoxygenState
{
public:
	// State Constructor
	DoxygenSTARTBASEState() : DoxygenDoxygenState()
	{

	}
	~DoxygenSTARTBASEState()
	{
	}
	void doxygen_section_tag(DoxygenContext &context)
	{
		// 1 transitions
		printf("[DoxygenSTARTBASEState]%s\n", __FUNCTION__);
		auto temp = context.current;
		context.setCurrentState((DoxygenDoxygenState *)new DoxygenSECTIONState());

		if (temp)
		{
			free(temp);
		}

	}
	void doxygen_c_plus_plus_comment(DoxygenContext &context)
	{
		printf("[DoxygenSTARTBASEState]%s\n", __FUNCTION__);
		auto temp = context.current;
		context.setCurrentState((DoxygenDoxygenState *)new DoxygenIDLEState());

		if (temp)
		{
			free(temp);
		}
	}


	void doxygen_right_brace_tag(DoxygenContext &context);
	void doxygen_page_tag(DoxygenContext &context);

};


/**************************************************************
 * State implementation for DoxygenPAGEState
 **************************************************************/
class DoxygenPAGEState: public DoxygenDoxygenState
{
public:
	// State Constructor
	DoxygenPAGEState() : DoxygenDoxygenState()
	{

	}

	// State Destructor
	~DoxygenPAGEState()
	{
	}
	void doxygen_c_plus_plus_comment(DoxygenContext &context)
	{
		printf("[DoxygenPAGEState]%s\n", __FUNCTION__);
		auto temp = context.current;
		context.setCurrentState((DoxygenDoxygenState *)new DoxygenIDLEState());

		if (temp)
		{
			free(temp);
		}
	}

	// OnEntry
	void OnEntry(DoxygenContext &context)
	{
		// OnEntry for state DoxygenPAGEState

	}

	// OnExit
	void OnExit(DoxygenContext &context)
	{
		// OnExit for state DoxygenPAGEState

	}

	// Events implementation for state  DoxygenPAGEState
	void doxygen_left_brace_tag(DoxygenContext &context)
	{
		// 1 transition(s)
		printf("[DoxygenPAGEState]%s\n", __FUNCTION__);
		auto temp = context.current;
		context.setCurrentState((DoxygenDoxygenState *)new DoxygenSTARTBASEState());

		if (temp)
		{
			free(temp);
		}

	}

	void doxygen_section_tag(DoxygenContext &context)
	{
		// 1 transition(s)

	}

	void doxygen_par_parameters_tag(DoxygenContext &context)
	{
		// 1 transition(s)

	}

	void doxygen_right_brace_tag(DoxygenContext &context)
	{
		// 1 transition(s)

	}

	void doxygen_end_c_plus_plus_comment(DoxygenContext &context)
	{
		// 1 transition(s)
		// 1 transition(s)
		*(context.filep) << "@{\n"
		                 *(context.filep) << "@section fill section template\n";
		*(context.filep) << "@par Parameters\n";
		*(context.filep) << " Name | Required | Type | Description\n";
		*(context.filep) << "-----|--------|------|----------\n";
		*(context.filep) << "@par Returns(Call)\n";
		*(context.filep) << "Name | Required | Type | Description\n";
		*(context.filep) << "-----|--------|------|----------\n";
		*(context.filep) <<
		                 "returnValue | yes | Boolean | True, when operation was successfull. False otherwise.\n";
		*(context.filep) << "@par Returns(Subscription)\n";
		*(context.filep) << "Not applicable.\n";
		*(context.filep) << "@}";
		auto temp = context.current;
		context.setCurrentState((DoxygenDoxygenState *)new DoxygenENDState());

		if (temp)
		{
			free(temp);
		}


	}


};
void  DoxygenSTARTBASEState:: doxygen_page_tag(DoxygenContext &context)
{
	printf("[DoxygenSTARTBASEState]%s\n", __FUNCTION__);
	auto temp = context.current;
	context.setCurrentState((DoxygenDoxygenState *)new DoxygenPAGEState());

	if (temp)
	{
		free(temp);
	}
}

void DoxygenIDLEState:: doxygen_page_tag(DoxygenContext &context)
{
	auto temp = context.current;
	context.setCurrentState((DoxygenDoxygenState *)new DoxygenPAGEState());

	if (temp)
	{
		free(temp);
	}
}
/**************************************************************
 * State implementation for DoxygenLEFTBRACEState
 **************************************************************/
class DoxygenLEFTBRACEState: public DoxygenDoxygenState
{
public:
	// State Constructor
	DoxygenLEFTBRACEState() : DoxygenDoxygenState()
	{

	}

	// State Destructor
	~DoxygenLEFTBRACEState()
	{
	}



	// OnEntry
	void OnEntry(DoxygenContext &context)
	{
		// OnEntry for state DoxygenLEFTBRACEState

	}

	// OnExit
	void OnExit(DoxygenContext &context)
	{
		// OnExit for state DoxygenLEFTBRACEState

	}
	void doxygen_right_brace_tag(DoxygenContext &context)
	{
		printf("[DoxygenLEFTBRACEState]%s\n", __FUNCTION__);
		auto temp = context.current;
		context.setCurrentState((DoxygenDoxygenState *)new DoxygenENDBASEState());

		if (temp)
		{
			free(temp);
		}
	}
	void doxygen_end_c_plus_plus_comment(DoxygenContext &context)
	{
		printf("[DoxygenLEFTBRACEState]%s\n", __FUNCTION__);
		printf("\n\n");
		auto temp = context.current;
		context.setCurrentState((DoxygenDoxygenState *)new DoxygenIDLEState());

		if (temp)
		{
			free(temp);
		}
	}
	void doxygen_c_plus_plus_comment(DoxygenContext &context)
	{
		printf("[DoxygenLEFTBRACEState]%s\n", __FUNCTION__);
		auto temp = context.current;
		context.setCurrentState((DoxygenDoxygenState *)new DoxygenIDLEState());

		if (temp)
		{
			free(temp);
		}
	}
	// Events implementation for state  DoxygenPAGEState
	void doxygen_page_tag(DoxygenContext &context)
	{
		printf("[DoxygenLEFTBRACEState]%s\n", __FUNCTION__);
		auto temp = context.current;
		context.setCurrentState((DoxygenDoxygenState *)new DoxygenPAGEState());

		if (temp)
		{
			free(temp);
		}

		// 1 transition(s)

	}

	// Events implementation for state  DoxygenLEFTBRACEState
	void doxygen_section_tag(DoxygenContext &context)
	{
		auto temp = context.current;
		context.setCurrentState((DoxygenDoxygenState *)new DoxygenPARAMETERSState());

		if (temp)
		{
			free(temp);
		}

		// 1 transition(s)

	}

};
void DoxygenIDLEState :: doxygen_c_plus_plus_comment(DoxygenContext &context)
{
	printf("[DoxygenIDLEState]In %s\n", __FUNCTION__);
	auto temp = context.current;
	context.setCurrentState((DoxygenDoxygenState *)new DoxygenLEFTBRACEState());

	if (temp)
	{
		free(temp);
	}

}

/**************************************************************
 * State implementation for DoxygenLSMESSAGEState
 **************************************************************/
class DoxygenLSMESSAGEState: public DoxygenDoxygenState
{
	// State Constructor
	DoxygenLSMESSAGEState() : DoxygenDoxygenState()
	{


	}

	// State Destructor
	~DoxygenLSMESSAGEState()
	{
	}
	void doxygen_c_plus_plus_comment(DoxygenContext &context)
	{
		printf("[DoxygenLSMESSAGEState]%s\n", __FUNCTION__);
		auto temp = context.current;
		context.setCurrentState((DoxygenDoxygenState *)new DoxygenIDLEState());

		if (temp)
		{
			free(temp);
		}
	}
	// OnEntry
	void OnEntry(DoxygenContext &context)
	{
		printf("[DoxygenLSMESSAGEState]%s\n", __FUNCTION__);
		context.setCurrentState(this);
	}

	// OnExit
	void OnExit(DoxygenContext &context)
	{
		printf("[DoxygenLSMESSAGEState]%s\n", __FUNCTION__);

	}
};

// Events implementation for state  DoxygenLSMESSAGEState



/**************************************************************
 * State implementation for DoxygenSTARTState
 **************************************************************/

// State Constructor
class DoxygenSTARTState: public DoxygenDoxygenState
{
public:
	DoxygenSTARTState() : DoxygenDoxygenState()
	{

	}

	// State Destructor
	~DoxygenSTARTState()
	{
	}



	// OnEntry
	void OnEntry(DoxygenContext &context) const
	{

	}

	// OnExit
	void OnExit(DoxygenContext &context) const
	{

	}

	// Events implementation for state  DoxygenSTARTState
	void doxygen_c_plus_plus_comment(DoxygenContext &context) const
	{
		printf("[DoxygenSTARTState]%s\n", __FUNCTION__);
		auto temp = context.current;
		context.setCurrentState((DoxygenDoxygenState *)new DoxygenIDLEState());

		if (temp)
		{
			free(temp);
		}

	}

	void doxygen_page_tag(DoxygenContext &context) const
	{

	}

	void doxygen_left_brace_tag(DoxygenContext &context) const
	{

	}

	void doxygen_section_tag(DoxygenContext &context) const
	{
		// 1 transition(s)

	}

	void doxygen_par_parameters_tag(DoxygenContext &context) const
	{
		// 1 transition(s)

	}

	void doxygen_right_brace_tag(DoxygenContext &context) const
	{
		// 1 transition(s)

	}

	void doxygen_end_c_plus_plus_comment(DoxygenContext &context) const
	{
		// 1 transition(s)

	}

};






/**************************************************************
 * State implementation for DoxygenRIGHTBRACEState
 **************************************************************/
class DoxygenRIGHTBRACEState: public DoxygenDoxygenState
{
public:
	// State Constructor
	DoxygenRIGHTBRACEState() : DoxygenDoxygenState()
	{

	}

	// State Destructor
	~DoxygenRIGHTBRACEState()
	{
	}
	// Events implementation for state  DoxygenSTARTState
	void doxygen_c_plus_plus_comment(DoxygenContext &context) const
	{
		printf("[DoxygenRIGHTBRACEState]%s\n", __FUNCTION__);
		auto temp = context.current;
		context.setCurrentState((DoxygenDoxygenState *)new DoxygenIDLEState());

		if (temp)
		{
			free(temp);
		}

	}
	// OnEntry
	void OnEntry(DoxygenContext &context)
	{
		// OnEntry for state DoxygenRIGHTBRACEState

	}

	// OnExit
	void OnExit(DoxygenContext &context)
	{
		// OnExit for state DoxygenRIGHTBRACEState

	}

	// Events implementation for state  DoxygenRIGHTBRACEState
	void doxygen_right_brace_tag(DoxygenContext &context)
	{
		// 1 transition(s)

	}


	void doxygen_end_c_plus_plus_comment(DoxygenContext &context)
	{

		printf("[DoxygenRIGHTBRACEState]%s\n", __FUNCTION__);
		printf("\n\n");
		auto temp = context.current;
		context.setCurrentState((DoxygenDoxygenState *)new DoxygenENDState());

		if (temp)
		{
			free(temp);
		}
	}

};
void DoxygenSTARTBASEState::doxygen_right_brace_tag(DoxygenContext &context)
{
	printf("[DoxygenSTARTBASEState]%s\n", __FUNCTION__);
	auto temp = context.current;
	context.setCurrentState((DoxygenDoxygenState *)new DoxygenRIGHTBRACEState());

	if (temp)
	{
		free(temp);
	}
}
/**************************************************************
 * State implementation for DoxygenFAULTState
 **************************************************************/
class DoxygenFAULTState: public DoxygenDoxygenState
{
public:
	// State Constructor
	DoxygenFAULTState() : DoxygenDoxygenState()
	{

	}

	// State Destructor
	~DoxygenFAULTState()
	{
	}


	// OnEntry
	void OnEntry(DoxygenContext &context)
	{
		// OnEntry for state DoxygenFAULTState

	}

	// OnExit
	void OnExit(DoxygenContext &context)
	{
		// OnExit for state DoxygenFAULTState

	}
};
// Events implementation for state  DoxygenFAULTState




class doxygenparser
{
public:
	doxygenparser()
	{
	};
	~doxygenparser() {};
	bool parse_file_insert_doxy_template(string filename, string template_file);
	bool camel_case_correction(string filename);
	string regexparser(string line);
	std::unordered_set<string> dictionary;
private:


};
int main(int argc , char **argv)
{

	DIR *dir;
	struct dirent *ent;
	std::ifstream dictionary_file;
	doxygenparser doxy_parser;
	string dict_line;

	if (argc < 4)
	{
		printf("enter ./doxygen directory_for_template_insertion template_formatfile  dictionary_file_name\n");
		return -1;

	}

	//load dictionary
	dictionary_file.open(argv[3]);

	if (dictionary_file.fail())
	{
		printf("file open failure %s %s %d\n", argv[3], __FUNCTION__, __LINE__);
		return false;

	}

	while (!dictionary_file.eof())
	{
		getline(dictionary_file, dict_line);
		doxy_parser.dictionary.emplace(dict_line);

	}

	string template_file = string(argv[2]);

	if ((dir = opendir(argv[1])) != NULL)
	{
		while ((ent = readdir(dir)) != NULL)
		{
			string str = string(ent->d_name);

			if (str.compare(0, 3, "src") == 0)
			{
				DIR *dir_internal;
				struct dirent *ent_internal;
				string internaldir = string(argv[1]) + "/" + str;

				if ((dir_internal = opendir(internaldir.c_str())) != NULL)
				{
					while ((ent_internal = readdir(dir_internal)) != NULL)
					{
						string filename = string(ent_internal->d_name);
						char *delimiter;
						char *point;

						if ((point = strrchr((char *)filename.c_str(), '.')) != NULL)
						{

							if (strcmp(point, ".c") == 0 || strcmp(point, ".cpp") == 0)
							{
								string internalfile = string(argv[1]) + "/" + str + "/" + filename;

								doxy_parser.parse_file_insert_doxy_template(internalfile, template_file);

							}

							if (strcmp(point, ".h") == 0)
							{
								string internalfile = string(argv[1]) + "/" + str + "/" + filename;
								printf("camel case correction %s\n", internalfile.c_str());
								doxy_parser.camel_case_correction(internalfile);

							}
						}

					}
				}
			}



		}

	}


}

bool doxygenparser::camel_case_correction(string filename)
{
	std::ifstream file;
	string line;

	file.open(filename.c_str());

	if (file.fail())
	{
		printf("file open failure %s %s %d\n", filename.c_str(), __FUNCTION__,
		       __LINE__);
		return false;

	}

	while (!file.eof())
	{
		string parse_string;
		getline(file, line);

		try
		{
			std::regex luna("^\\s*#define\\s*LUNA_METHOD\.*");
			std::smatch match;

			if (std::regex_match(line, match, luna) && match.size() >= 1)
			{

				char *saveptr;
				char *delimiter = " ";
				char *str = strtok_r((char *)line.c_str(), (const char *)delimiter, &saveptr);
				str = strtok_r((char *)NULL, (const char *)delimiter, &saveptr);
				str = strtok_r((char *)NULL, (const char *)delimiter, &saveptr);
				std::regex camel_case(" (^\"[a-z]{1}[a-z]+){1,}([A-Z]{1}[a-z]+){1,}");
				std::smatch match;
				std::regex normal_case("^\"[a-z]+\"$");

				if (std::regex_match(string(str), match, camel_case) && match.size() >= 1)
				{
					printf("came case %s\n", str);


				}
				else if (std::regex_match(string(str), match, normal_case) && match.size() >= 1)
				{
					printf("normal case %s\n", str);
					//Change to camel case here
					//Check each word in dictionary and then start changing
					string dic_match_string = " ";
					//dic_match_string =

				}
				else
				{
					printf(" case %s\n", str);

				}



			}



		}
		catch (const std::regex_error &e)
		{
			std::cout << "regex_error caught: " << e.what() << '\n';

			if (e.code() == std::regex_constants::error_brack)
			{

			}

		}

	}

}
bool doxygenparser::parse_file_insert_doxy_template(string filename,
        string templatefile)
{
	string line;
	char *delimiter;
	std::ifstream file;
	string outputfile;
	outputfile = filename + "backup";
	DoxygenContext *doxygenmachine = new DoxygenContext();
	DoxygenDoxygenState *s = (DoxygenIDLEState *)new DoxygenIDLEState();
	doxygenmachine->setCurrentState(s);
	std::unordered_map<string, std::function<void()>> hash_map =
	{
		{"comment", [doxygenmachine]()
			{
				doxygenmachine->doxygen_c_plus_plus_comment();
			}
		},
		{"page", [doxygenmachine]()
			{
				doxygenmachine->doxygen_page_tag();
			}
		},
		{"startbrace", [doxygenmachine]()
			{
				doxygenmachine->doxygen_left_brace_tag();
			}
		},
		{"section", [doxygenmachine]()
			{
				doxygenmachine->doxygen_section_tag();
			}
		},
		{"par", [doxygenmachine]()
			{
				doxygenmachine->doxygen_par_parameters_tag();
			}
		},
		{"endbrace", [doxygenmachine]()
			{
				doxygenmachine->doxygen_right_brace_tag();
			}
		},
		{"endcomment", [doxygenmachine]()
			{
				doxygenmachine->doxygen_end_c_plus_plus_comment();
			}
		},
		{"lsfunction", [doxygenmachine]()
			{
				doxygenmachine->doxygen_ls_tag();
			}
		}


	};
	std::ofstream output_file_fp(outputfile);

	if (output_file_fp.is_open())
	{


	}

	file.open(filename.c_str());

	if (file.fail())
	{
		printf("file open failure %s\n", filename.c_str());
		return false;

	}

	while (!file.eof())
	{
		string parse_string;
		getline(file, line);

		parse_string = regexparser(line);
		auto search = hash_map.find(parse_string);

		if (search != hash_map.end())
		{
			printf("%s %s\n", line.c_str(), parse_string.c_str());
			doxygenmachine->filep = &output_file_fp;
			doxygenmachine->template_file = templatefile;
			search->second();
			output_file_fp << line << "\n";

		}
		else
		{
			output_file_fp << line << "\n";
		}

	}

	if (doxygenmachine)
	{
		free(doxygenmachine);
	}

}
string doxygenparser::regexparser(string line)
{
	string str = "";

	try
	{
		std::regex c_comment("^\\s*\/\\*\\*");
		std::smatch match;

		if (std::regex_match(line, match, c_comment) && match.size() >= 1)
		{


			str = "comment";
		}

		std::regex startbrace("^\\s*@\\{");

		if (std::regex_match(line, match, startbrace) && match.size() >= 1)
		{

			str = "startbrace";

		}

		std::regex par("^\\s*@par\\s*\.*");

		if (std::regex_match(line, match, par) && match.size() >= 1)
		{

			str = "par";
		}

		std::regex section("^\\s*@section\\s*\.*");

		if (std::regex_match(line, match, section) && match.size() >= 1)
		{

			str = "section";
		}

		std::regex page("^\\s*@page\\s*\.*");

		if (std::regex_match(line, match, page) && match.size() >= 1)
		{

			str = "page";
		}

		std::regex re("^(\\w)+\\s*.*\\(.*Message\\s*..*\\)");

		if (std::regex_match(line, match, re) && match.size() >= 1)
		{

			str = "lsfunction";

		}

		std::regex endbrace("^\\s*\\@\\}");

		if (std::regex_match(line, match, endbrace) && match.size() >= 1)
		{

			str = "endbrace";

		}

		std::regex endcomment("^\\s*\\*\\/");

		if (std::regex_match(line, match, endcomment) && match.size() >= 1)
		{

			str = "endcomment";

		}

		else
		{
			//printf("failure \n");
		}
	}
	catch (const std::regex_error &e)
	{
		std::cout << "regex_error caught: " << e.what() << '\n';

		if (e.code() == std::regex_constants::error_brack)
		{
			//   std::cout << "The code was error_brack\n";
		}

	}

	return str;

}

