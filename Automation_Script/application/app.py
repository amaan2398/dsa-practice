from application import settings
import os
import logging
from datetime import datetime

class run:

    def __init__(self):
        self.setting = settings.setting()
        self.user_name = self.setting.INFO['username']
        self.new_topic = False
        self.CODING_DIR = os.path.join(self.setting.BASE_DIR_PATH,"Coding")
        self.logger = logging.getLogger('app.run')
        self.runner()
    
    def listout_dir(self):
        self.list_dir = os.listdir(self.CODING_DIR)

    def take_input(self):
        #Topic 
        self.listout_dir()
        print("TOPIC DIR LIST:")
        for i,dir_name in enumerate(self.list_dir):
            print(str(i)+".",dir_name)
        print(str(len(self.list_dir))+".","Other")
        choice = int(input("Choice: "))
        if ((choice >= 0) and (choice < len(self.list_dir))):
            self.topic = self.list_dir[choice]
        else:
            self.topic = input("New topic name: ")
            self.new_topic = True
        # print(self.list_dir)

        #Problem 
        print("PROBLEM STATEMRNT LIST:")
        list_dir_pt = []
        if not self.new_topic:
            list_dir_pt = os.listdir(os.path.join(self.CODING_DIR,self.topic))
        for i,dir_name in enumerate(list_dir_pt):
            print(str(i)+".",dir_name)
        print(str(len(list_dir_pt))+".","Other")
        choice = int(input("Choice: "))
        if ((choice >= 0) and (choice < len(list_dir_pt))):
            self.problem_title = list_dir_pt[choice]
        else:
            self.problem_title = "_".join(input("Problem title:").strip().split(" "))
        # print(self.problem_title)
    def sample_code_line_data(self,filename):
        lines = []
        file1 = open(os.path.join(self.sample_code_dir,filename),"r")
        lines += file1.readlines()
        file1.close()
        return lines

    def create_files(self):
        #Topic Dir Creation
        topic_dir = os.path.join(self.CODING_DIR,self.topic)
        if ((not os.path.exists(topic_dir)) or (self.new_topic)):
            os.mkdir(topic_dir)
            self.logger.info(f"New directory created '{self.topic}'!")
        if (not os.path.exists(topic_dir)):
            self.logger.error(f"Issue while creating '{self.topic}'!")
        
        #Problem Dir Creation
        problem_dir = os.path.join(topic_dir,self.problem_title)
        if (not os.path.exists(problem_dir)):
            os.mkdir(problem_dir)
            self.logger.info(f"New directory created '{self.problem_title}'!")
        if (not os.path.exists(problem_dir)):
            self.logger.error(f"Issue while creating '{self.problem_title}'!")
        
        #Copy Sample Code file to Problem Dir
        self.sample_code_dir=os.path.join(self.setting.BASE_DIR_PATH,"SampleCode")
        filename = "code.cpp"
        lines = self.sample_code_line_data(filename)
        new_lines = []
        approach_idx = 0
        for idx,line in enumerate(lines):
            if (len(line.strip())>= 1) and (line.strip()[0] == "@"):
                data = line.strip().split(" ")[1]
                if data == "Creator:":
                    line= line[:-1]+self.user_name+'\n'
                if data == "Problem_Title:":
                    line = line[:-1]+self.problem_title+'\n'
                if data == "Date_Time:":
                    line = line[:-1]+datetime.now().strftime("%B %d, %Y %H:%M:%S")+'\n'
                if data == "Approach:":
                    approach_idx = idx
            new_lines.append(line)
        if not os.path.exists(os.path.join(problem_dir,"B"+filename)):
            file2 = open(os.path.join(problem_dir,"B"+filename),'w')
            t_new_lines =[]
            for k,d in enumerate(new_lines):
                if (k == approach_idx):
                    t_new_lines.append(d[:-1]+"Broad Force"+"\n" )  
                else: 
                    t_new_lines.append(d)
            file2.writelines(t_new_lines)
            file2.close()
        
        i = 1
        while os.path.exists(os.path.join(problem_dir,"op"+str(i)+filename)):
            i+=1
        file2 = open(os.path.join(problem_dir,"op"+str(i)+filename),'w')
        t_new_lines = []
        for k,d in enumerate(new_lines):
            if (k == approach_idx):
                t_new_lines.append(d[:-1]+"Optimized Approach "+str(i)+"\n" )  
            else: 
                t_new_lines.append(d)
        file2.writelines(t_new_lines)
        file2.close()
        

    def runner(self):
        self.take_input()
        self.create_files()