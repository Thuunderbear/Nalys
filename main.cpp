
using namespace std;
#include "inja/inja.hpp"
int main( int argc, char *argv[]){
    string title,text,count,output,footer;
    string temp;
    std::ofstream file;

        //For inja
    inja::Environment env;
    inja::Template template_html = env.parse_template("template/template_html.txt");

    nlohmann::json data;
    
    std::string result = "";
    for(int i = 1; i < argc; ++i)  {
        cout << argv[i] << '\n';
       
        if (strcmp(argv[i],"--title")== 0){
            title = argv[i+1];
        }
        if (strcmp(argv[i],"--text")== 0){
            text = argv[i+1];
        }
        if (strcmp(argv[i],"--count")== 0){
            count = argv[i+1];
        }
        if (strcmp(argv[i],"--output")== 0){
            output = argv[i+1];
        }
        if (strcmp(argv[i],"--footer")== 0){
            footer = argv[i+1];
        }

    }
    if(title.empty() || text.empty() || count.empty() || output.empty()){
        cout << "missing argument(s)";
        cout <<title.empty() << text.empty() << count.empty() << output.empty() << '\n';
    }
    else{
        // create a fie using inja
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
        result = env.render(template_html,data);
        cout << result;
    }
}