#include <FS.h>
void ptintdeb(String s)
{
  Serial.println(s);
}
#define DEBG ptintdeb
#define PARAM_SOUND_TYPE "sound_type"
#define PARAM_LIGHT_TYPE "light_type"
#define PARAM_BRIGHTNES_TYPE "brightnes_type"
#define PARAM_COLOR_TYPE "color_type"

String json_config;
String json_default_config;
int var_num = 0;
bool save_flag = false;

void create_param(String name, String value)
{
    if (var_num == 0)
        json_default_config = "{\"";
    else
        json_default_config.replace("}", ",\"");
    json_default_config += name;
    json_default_config += "\":\"";
    json_default_config += value;
    json_default_config += "\"}";
    var_num++;
}

void write_param(String name, String value)
{
    DEBG(F("Write param value: "));
     DEBG(value);
    String result;
    DynamicJsonBuffer jsonBuffer;
    JsonObject &root = jsonBuffer.parseObject(json_config);
    root[name] = value;
    root.printTo(result);
    json_config = result;
    result = "";
}

String param(String name)
{
    DynamicJsonBuffer jsonBuffer;
    JsonObject &root = jsonBuffer.parseObject(json_config);
    return root[name].as<String>();
}

void save_param()
{
    if (!save_flag)
        return;
    File configFile = SPIFFS.open(F("/config.json"), "w");
    configFile.print(json_config);
    DEBG(F("Save Config"));
    save_flag = false;
}

void create_parameters()
{
    DEBG(F("create_parameters"));
    create_param(F(PARAM_BRIGHTNES_TYPE), "110");
    create_param(F(PARAM_LIGHT_TYPE), "0");
    create_param(F(PARAM_COLOR_TYPE), "0"); 
    create_param(F(PARAM_SOUND_TYPE), "0");
    save_flag = true;
    save_param();
}

void load_default_param()
{
    create_parameters();
    json_config = json_default_config;
    json_default_config = "";
    DEBG(F("Load default Config"));
}


void load_param()
{
    File pre_configFile = SPIFFS.open(F("/config.json"), "r");
    if (pre_configFile.readString() == "")
    {
        DEBG(F("Failed to open config file"));
        load_default_param();
        save_flag = true;
        save_param();
    }
    File configFile = SPIFFS.open(F("/config.json"), "r");
    json_config = configFile.readString();
    DEBG("");
    DEBG(json_config);
    DEBG(F("JSON config loaded"));
}