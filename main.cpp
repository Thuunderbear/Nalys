
using namespace std;
#include "inja/inja.hpp"
#include <iostream>

int main( int argc, char *argv[]){

    string title,text,count,output_path,footer;
    string temp;
    std::ofstream file_output;

    //For inja
    inja::Environment env;
    inja::Template template_html = env.parse_template("template/template_html.txt");

    nlohmann::json data;
    
    std::string result = "";

    // look at all the arguments and find the necessary ones
    for(int i = 1; i < argc; ++i)  {
        cout << argv[i] << '\n';
       
        if (strcmp(argv[i],"--title")== 0){     // search the title of the document
            title = argv[i+1];
        }
        if (strcmp(argv[i],"--text")== 0){      // search the text of the document
            text = argv[i+1];
        }
        if (strcmp(argv[i],"--count")== 0){     // search hom many times the text will be write
            count = argv[i+1];
        }
        if (strcmp(argv[i],"--output")== 0){    // search where the document will be saved
            output_path = argv[i+1];
        }
        if (strcmp(argv[i],"--footer")== 0){    // search if the user has selected a footer
            footer = argv[i+1];
        }

    }
    if(title.empty() || text.empty() || count.empty() || output_path.empty()){  // check if all the necessaires argements are enter 
        cout << "missing argument(s)";
        
        // For debug
        //cout <<title.empty() << text.empty() << count.empty() << output_path.empty() << '\n';
    }
    else{

        // create a document to the selected path
        file_output = std::ofstream(output_path+"index.html");
        
        // create a json file using all the argument for the template engine
        data["title"] = title;
        for (auto y=0; y < stoi(count); y++){
             temp += text;
        }
        data["text"] = temp;
        
        if (!footer.empty()){
            data["footer"]= footer;
        }
        else{
           data["footer"]= "<!--Nothing here-->";  
        }

        // render the template using inja as the template engine 
        result = env.render(template_html,data);

        // save the result 
        file_output << result;
        file_output.close();
    }
}