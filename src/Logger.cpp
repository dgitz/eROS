#include <eros/Logger.h>

Logger::Logger() : verbosity(Level::Type::WARN) {
}
Logger::~Logger() {
}
Logger::Logger(std::string level, std::string directory, std::string name) {
    console_print = true;
    use_ROS_logger = false;
    verbosity = Level::LevelType(level);
    line_counter = 0;
    replace(name.begin(), name.end(), '/', '_');
    char buffer[100];
    sprintf(buffer, "%s.out", name.c_str());
    sprintf(file_path, "%s/%s", directory.c_str(), buffer);
    std::ofstream log_file;
    log_file.open(file_path);  // Overwrite file.
    log_file.close();
}
Logger::Logger(std::string level, std::string name) {
    console_print = true;
    use_ROS_logger = false;
    verbosity = Level::LevelType(level);
    line_counter = 0;
    if (name.at(0) == '/') {
        name.erase(name.begin());
    }
    replace(name.begin(), name.end(), '/', '_');
    node_name = name;
    char buffer[100];
    sprintf(buffer, "%s.out", name.c_str());

    sprintf(file_path, "/home/robot/var/log/output/%s", buffer);
    std::ofstream log_file;
    log_file.open(file_path);  // Overwrite file.
    log_file.close();
}

void Logger::set_logverbosity(Level::Type level) {
    if (level == verbosity) {
        return;
    }
    if ((level < Level::Type::DEBUG) or (level > Level::Type::FATAL)) {
        return;
    }
    std::string tempstr = "Changing Log Level from " + Level::LevelString(verbosity) + " to " +
                          Level::LevelString(level) + ".";
    verbosity = level;
    print_log("", 0, verbosity, tempstr);
}
Logger::LoggerStatus Logger::LOG_DEBUG(std::string filename,
                                       uint64_t linenumber,
                                       std::string tempstr) {
    return print_log(filename, linenumber, Level::Type::DEBUG, tempstr);
}
Logger::LoggerStatus Logger::LOG_INFO(std::string filename,
                                      uint64_t linenumber,
                                      std::string tempstr) {
    return print_log(filename, linenumber, Level::Type::INFO, tempstr);
}
Logger::LoggerStatus Logger::LOG_NOTICE(std::string filename,
                                        uint64_t linenumber,
                                        std::string tempstr) {
    return print_log(filename, linenumber, Level::Type::NOTICE, tempstr);
}
Logger::LoggerStatus Logger::LOG_WARN(std::string filename,
                                      uint64_t linenumber,
                                      std::string tempstr) {
    return print_log(filename, linenumber, Level::Type::WARN, tempstr);
}
Logger::LoggerStatus Logger::LOG_ERROR(std::string filename,
                                       uint64_t linenumber,
                                       std::string tempstr) {
    return print_log(filename, linenumber, Level::Type::ERROR, tempstr);
}
Logger::LoggerStatus Logger::LOG_FATAL(std::string filename,
                                       uint64_t linenumber,
                                       std::string tempstr) {
    return print_log(filename, linenumber, Level::Type::FATAL, tempstr);
}
Logger::LoggerStatus Logger::LOG_DIAGNOSTIC(std::string filename,
                                            uint64_t linenumber,
                                            Diagnostic::DiagnosticDefinition diagnostic) {
    char tempstr[2048];

    sprintf(
        tempstr,
        "Device: %s System: %s Subsystem: %s Component: %s Type: %s Message: %s Description: %s",
        diagnostic.device_name.c_str(),
        System::MainSystemString(diagnostic.system).c_str(),
        System::SubSystemString(diagnostic.subsystem).c_str(),
        System::ComponentString(diagnostic.component).c_str(),
        Diagnostic::DiagnosticTypeString(diagnostic.type).c_str(),
        Diagnostic::DiagnosticMessageString(diagnostic.message).c_str(),
        diagnostic.description.c_str());
    switch (diagnostic.level) {
        case Level::Type::DEBUG:
            return LOG_DEBUG(filename, linenumber, std::string(tempstr));
            break;
        case Level::Type::INFO: return LOG_INFO(filename, linenumber, std::string(tempstr)); break;
        case Level::Type::NOTICE:
            return LOG_NOTICE(filename, linenumber, std::string(tempstr));
            break;
        case Level::Type::WARN: return LOG_WARN(filename, linenumber, std::string(tempstr)); break;
        case Level::Type::ERROR:
            return LOG_ERROR(filename, linenumber, std::string(tempstr));
            break;
        case Level::Type::FATAL:
            return LOG_FATAL(filename, linenumber, std::string(tempstr));
            break;
        default:
            return LOG_ERROR("", 0, "UNKNOWN LEVEL: " + std::to_string((uint8_t)diagnostic.level));
            break;
    }
}
Logger::LoggerStatus Logger::print_log(std::string filename,
                                       uint64_t linenumber,
                                       Level::Type level,
                                       std::string tempstr) {
    time_t rawtime;
    struct tm* timeinfo;
    char datebuffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(datebuffer, 80, "%d/%m/%Y %I:%M:%S", timeinfo);
    std::string str(datebuffer);
    log_file.open(file_path, std::ios::out | std::ios::app | std::ios::binary | std::ios::ate);
    std::string swcode_info = "";
    if (linenumber > 0) {
        swcode_info = filename + "(" + std::to_string(linenumber) + ")";
    }
    if (log_file.is_open() == true) {
        if (level >= verbosity) {
            line_counter++;
            switch (level) {
                case Level::Type::DEBUG:
                    log_file << "[" << datebuffer << "]: DEBUG: " << swcode_info << " " << tempstr
                             << std::endl;
                    if (console_print) {
                        printf(
                            "[%s %s]: DEBUG: %s\n", datebuffer, node_name.c_str(), tempstr.c_str());
                    }
#ifdef ROS_INSTALLED
                    if (use_ROS_logger == true) {
                        ROS_DEBUG("%s", tempstr.c_str());
                    }
#endif
                    break;
                case Level::Type::INFO:
                    log_file << "[" << datebuffer << "]: INFO: " << swcode_info << " " << tempstr
                             << std::endl;
                    if (console_print) {
                        printf(
                            "[%s %s]: INFO: %s\n", datebuffer, node_name.c_str(), tempstr.c_str());
                    }
#ifdef ROS_INSTALLED
                    if (use_ROS_logger == true) {
                        ROS_INFO("%s", tempstr.c_str());
                    }
#endif
                    break;
                case Level::Type::NOTICE:
                    log_file << "[" << datebuffer << "]: NOTICE: " << swcode_info << " " << tempstr
                             << std::endl;
                    if (console_print) {
                        printf("%s[%s %s]: NOTICE: %s%s\n",
                               GREEN_FOREGROUND.c_str(),
                               datebuffer,
                               node_name.c_str(),
                               tempstr.c_str(),
                               END_COLOR.c_str());
                    }
#ifdef ROS_INSTALLED
                    if (use_ROS_logger == true) {
                        ROS_INFO("%s", tempstr.c_str());
                    }
#endif
                    break;
                case Level::Type::WARN:
                    log_file << "[" << datebuffer << "]: WARN: " << swcode_info << " " << tempstr
                             << std::endl;
                    if (console_print) {
                        printf("%s[%s %s]: WARN: %s%s\n",
                               YELLOW_FOREGROUND.c_str(),
                               datebuffer,
                               node_name.c_str(),
                               tempstr.c_str(),
                               END_COLOR.c_str());
                    }
#ifdef ROS_INSTALLED
                    if (use_ROS_logger == true) {
                        ROS_WARN("%s", tempstr.c_str());
                    }
#endif
                    break;
                case Level::Type::ERROR:
                    log_file << "[" << datebuffer << "]: ERROR: " << swcode_info << " " << tempstr
                             << std::endl;
                    if (console_print) {
                        printf("%s[%s %s]: ERROR: %s%s\n",
                               RED_FOREGROUND.c_str(),
                               datebuffer,
                               node_name.c_str(),
                               tempstr.c_str(),
                               END_COLOR.c_str());
                    }
#ifdef ROS_INSTALLED
                    if (use_ROS_logger == true) {
                        ROS_ERROR("%s", tempstr.c_str());
                    }
#endif
                    break;
                case Level::Type::FATAL:
                    log_file << "[" << datebuffer << "]: FATAL: " << swcode_info << " " << tempstr
                             << std::endl;
                    if (console_print) {
                        printf("%s[%s %s]: FATAL: %s%s\n",
                               RED_FOREGROUND.c_str(),
                               datebuffer,
                               node_name.c_str(),
                               tempstr.c_str(),
                               END_COLOR.c_str());
                    }
#ifdef ROS_INSTALLED
                    if (use_ROS_logger == true) {
                        ROS_FATAL("%s", tempstr.c_str());
                    }
#endif
                    break;
                default: break;
            }
        }
        else {
            return LoggerStatus::LOG_SUPPRESSED;
        }
    }
    else {
        printf("%s[%s %s]: ERROR: UNABLE TO OPEN OUTPUT FILE: %s%s\n",
               RED_FOREGROUND.c_str(),
               datebuffer,
               node_name.c_str(),
               file_path,
               END_COLOR.c_str());
        return LoggerStatus::FAILED_TO_OPEN;
    }
    log_file.close();
    if (line_counter > 5000) {
        log_file.open(file_path);  // Overwrite file.
        log_file.close();
        line_counter = 0;
    }
    return LoggerStatus::LOG_WRITTEN;
}
