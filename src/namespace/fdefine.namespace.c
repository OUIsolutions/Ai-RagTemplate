
void start_namespace(){
    args = newCArgvParseNamespace();
    dtw = newDtwNamespace();
    openai = newOpenAiNamespace();
    bear = newBearHttpsNamespace();
}