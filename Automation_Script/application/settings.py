from operator import sub
import os
import logging
from pathlib import Path
from configparser import ConfigParser


class setting:
    BASE_DIR_PATH = None
    CONFIG_FILE_NAME = 'config.ini'
    LOGGING_FILE_NAME = 'app.log'
    INFO = dict()

    def __init__(self):
        setting.BASE_DIR_PATH = os.getcwd()
        self.logging_app()
        self.config_app()
    
    def logging_app(self):
        """
        This Method is used for logging basic configuration 
        """
        #Format is => Time
        format = r"%(asctime)s    %(name)s - %(levelname)s : %(message)s"
        logging.basicConfig(format=format,level=logging.INFO,handlers=[
            logging.FileHandler(filename =setting.LOGGING_FILE_NAME,mode='a'),
            logging.StreamHandler()
        ])
        self.logger = logging.getLogger('settings.setting')

    def config_app(self):
        config = ConfigParser()
        config_full_path = os.path.join(setting.BASE_DIR_PATH ,setting.CONFIG_FILE_NAME)
        if os.path.exists(config_full_path):
            config.read(config_full_path)
            self.logger.info("Config file Read successfully!")
        else:
            self.logger.error("While reading config file!")
        for section in config.sections():
            for subsection in config[section]:
                setting.INFO[section+subsection]=config[section][subsection]
