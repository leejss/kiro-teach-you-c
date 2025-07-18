/*
 * File Processing - Text Processing, Parsing, and Data Extraction
 * 
 * This program demonstrates:
 * - Text file parsing and data extraction
 * - CSV file processing
 * - Log file analysis
 * - Configuration file parsing
 * 
 * For frontend developers: Like processing server responses or config files,
 * but with manual parsing and explicit memory management.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Structures for different file formats
typedef struct {
    int id;
    char name[50];
    char email[100];
    int age;
    double salary;
} Person;

typedef struct {
    char timestamp[20];
    char level[10];
    char component[20];
    char message[200];
} LogEntry;

typedef struct {
    char key[50];
    char value[100];
} ConfigEntry;

// Function prototypes
void demonstrate_csv_processing(void);
void demonstrate_log_file_analysis(void);
void demonstrate_config_file_parsing(void);
void demonstrate_text_statistics(void);
void create_sample_files(void);
char* trim_whitespace(char* str);
int parse_csv_line(char* line, Person* person);
int parse_log_line(char* line, LogEntry* entry);
int parse_config_line(char* line, ConfigEntry* entry);

void create_sample_files(void) {
    printf("=== Creating Sample Files ===\n");
    
    // Create CSV file
    FILE* csv_file = fopen("employees.csv", "w");
    if (csv_file != NULL) {
        fprintf(csv_file, "id,name,email,age,salary\n");
        fprintf(csv_file, "1001,\"Alice Johnson\",alice@company.com,28,75000.50\n");
        fprintf(csv_file, "1002,\"Bob Smith\",bob@company.com,35,68000.00\n");
        fprintf(csv_file, "1003,\"Carol Davis\",carol@company.com,42,82000.75\n");
        fprintf(csv_file, "1004,\"David Wilson\",david@company.com,29,71500.25\n");
        fprintf(csv_file, "1005,\"Eve Brown\",eve@company.com,33,79000.00\n");
        fclose(csv_file);
        printf("Created employees.csv\n");
    }
    
    // Create log file
    FILE* log_file = fopen("application.log", "w");
    if (log_file != NULL) {
        fprintf(log_file, "2024-01-15 09:30:15 INFO  Server    Application started successfully\n");
        fprintf(log_file, "2024-01-15 09:30:16 INFO  Database  Connected to database server\n");
        fprintf(log_file, "2024-01-15 09:35:22 WARN  Auth      Failed login attempt for user 'admin'\n");
        fprintf(log_file, "2024-01-15 09:35:45 ERROR Network   Connection timeout to external API\n");
        fprintf(log_file, "2024-01-15 09:36:01 INFO  Auth      User 'alice' logged in successfully\n");
        fprintf(log_file, "2024-01-15 09:40:12 DEBUG Cache     Cache hit rate: 85.2%\n");
        fprintf(log_file, "2024-01-15 09:45:33 ERROR Database  Query execution failed: table not found\n");
        fprintf(log_file, "2024-01-15 09:50:44 INFO  Server    Processing 1250 requests/minute\n");
        fclose(log_file);
        printf("Created application.log\n");
    }
    
    // Create config file
    FILE* config_file = fopen("app.conf", "w");
    if (config_file != NULL) {
        fprintf(config_file, "# Application Configuration\n");
        fprintf(config_file, "server_port = 8080\n");
        fprintf(config_file, "database_host = localhost\n");
        fprintf(config_file, "database_port = 5432\n");
        fprintf(config_file, "database_name = myapp\n");
        fprintf(config_file, "max_connections = 100\n");
        fprintf(config_file, "timeout_seconds = 30\n");
        fprintf(config_file, "debug_mode = true\n");
        fprintf(config_file, "log_level = INFO\n");
        fprintf(config_file, "# Cache settings\n");
        fprintf(config_file, "cache_size = 1024\n");
        fprintf(config_file, "cache_ttl = 3600\n");
        fclose(config_file);
        printf("Created app.conf\n");
    }
    
    // Create text file for statistics
    FILE* text_file = fopen("sample_text.txt", "w");
    if (text_file != NULL) {
        fprintf(text_file, "The quick brown fox jumps over the lazy dog.\n");
        fprintf(text_file, "This sentence contains every letter of the alphabet.\n");
        fprintf(text_file, "File processing in C requires careful memory management.\n");
        fprintf(text_file, "Unlike JavaScript, C doesn't have built-in JSON parsing.\n");
        fprintf(text_file, "Manual string parsing gives you complete control.\n");
        fprintf(text_file, "Performance is excellent with proper buffer management.\n");
        fclose(text_file);
        printf("Created sample_text.txt\n");
    }
    printf("\n");
}

void demonstrate_csv_processing(void) {
    printf("=== CSV File Processing ===\n");
    
    FILE* file = fopen("employees.csv", "r");
    if (file == NULL) {
        perror("Failed to open CSV file");
        return;
    }
    
    char line[256];
    Person employees[10];
    int employee_count = 0;
    int line_number = 0;
    
    printf("Processing CSV file:\n");
    
    while (fgets(line, sizeof(line), file) != NULL && employee_count < 10) {
        line_number++;
        
        // Remove newline
        line[strcspn(line, "\n")] = '\0';
        
        // Skip header line
        if (line_number == 1) {
            printf("  Header: %s\n", line);
            continue;
        }
        
        // Parse CSV line
        if (parse_csv_line(line, &employees[employee_count])) {
            printf("  Employee %d: ID=%d, Name=\"%s\", Email=%s, Age=%d, Salary=$%.2f\n",
                   employee_count + 1,
                   employees[employee_count].id,
                   employees[employee_count].name,
                   employees[employee_count].email,
                   employees[employee_count].age,
                   employees[employee_count].salary);
            employee_count++;
        } else {
            printf("  Error parsing line %d: %s\n", line_number, line);
        }
    }
    
    fclose(file);
    
    // Calculate statistics
    if (employee_count > 0) {
        double total_salary = 0.0;
        int total_age = 0;
        
        for (int i = 0; i < employee_count; i++) {
            total_salary += employees[i].salary;
            total_age += employees[i].age;
        }
        
        printf("\nCSV Statistics:\n");
        printf("  Total employees: %d\n", employee_count);
        printf("  Average salary: $%.2f\n", total_salary / employee_count);
        printf("  Average age: %.1f years\n", (double)total_age / employee_count);
        
        // Find highest paid employee
        int highest_paid_index = 0;
        for (int i = 1; i < employee_count; i++) {
            if (employees[i].salary > employees[highest_paid_index].salary) {
                highest_paid_index = i;
            }
        }
        
        printf("  Highest paid: %s ($%.2f)\n",
               employees[highest_paid_index].name,
               employees[highest_paid_index].salary);
    }
    printf("\n");
}

void demonstrate_log_file_analysis(void) {
    printf("=== Log File Analysis ===\n");
    
    FILE* file = fopen("application.log", "r");
    if (file == NULL) {
        perror("Failed to open log file");
        return;
    }
    
    char line[512];
    LogEntry entries[100];
    int entry_count = 0;
    int error_count = 0;
    int warning_count = 0;
    int info_count = 0;
    
    printf("Analyzing log file:\n");
    
    while (fgets(line, sizeof(line), file) != NULL && entry_count < 100) {
        // Remove newline
        line[strcspn(line, "\n")] = '\0';
        
        if (parse_log_line(line, &entries[entry_count])) {
            printf("  [%s] %s %s: %s\n",
                   entries[entry_count].timestamp,
                   entries[entry_count].level,
                   entries[entry_count].component,
                   entries[entry_count].message);
            
            // Count by level
            if (strcmp(entries[entry_count].level, "ERROR") == 0) {
                error_count++;
            } else if (strcmp(entries[entry_count].level, "WARN") == 0) {
                warning_count++;
            } else if (strcmp(entries[entry_count].level, "INFO") == 0) {
                info_count++;
            }
            
            entry_count++;
        }
    }
    
    fclose(file);
    
    printf("\nLog Analysis Results:\n");
    printf("  Total entries: %d\n", entry_count);
    printf("  Errors: %d\n", error_count);
    printf("  Warnings: %d\n", warning_count);
    printf("  Info messages: %d\n", info_count);
    
    // Show error messages
    if (error_count > 0) {
        printf("\nError messages:\n");
        for (int i = 0; i < entry_count; i++) {
            if (strcmp(entries[i].level, "ERROR") == 0) {
                printf("  %s [%s]: %s\n",
                       entries[i].timestamp,
                       entries[i].component,
                       entries[i].message);
            }
        }
    }
    
    // Component activity analysis
    printf("\nComponent activity:\n");
    const char* components[] = {"Server", "Database", "Auth", "Network", "Cache"};
    int component_count = sizeof(components) / sizeof(components[0]);
    
    for (int i = 0; i < component_count; i++) {
        int count = 0;
        for (int j = 0; j < entry_count; j++) {
            if (strcmp(entries[j].component, components[i]) == 0) {
                count++;
            }
        }
        if (count > 0) {
            printf("  %s: %d messages\n", components[i], count);
        }
    }
    printf("\n");
}

void demonstrate_config_file_parsing(void) {
    printf("=== Configuration File Parsing ===\n");
    
    FILE* file = fopen("app.conf", "r");
    if (file == NULL) {
        perror("Failed to open config file");
        return;
    }
    
    char line[256];
    ConfigEntry config[20];
    int config_count = 0;
    int line_number = 0;
    
    printf("Parsing configuration file:\n");
    
    while (fgets(line, sizeof(line), file) != NULL && config_count < 20) {
        line_number++;
        
        // Remove newline
        line[strcspn(line, "\n")] = '\0';
        
        // Skip empty lines and comments
        char* trimmed = trim_whitespace(line);
        if (strlen(trimmed) == 0 || trimmed[0] == '#') {
            printf("  Line %d: %s (skipped)\n", line_number, 
                   strlen(trimmed) == 0 ? "empty" : "comment");
            continue;
        }
        
        if (parse_config_line(trimmed, &config[config_count])) {
            printf("  %s = %s\n", config[config_count].key, config[config_count].value);
            config_count++;
        } else {
            printf("  Error parsing line %d: %s\n", line_number, trimmed);
        }
    }
    
    fclose(file);
    
    printf("\nConfiguration Summary:\n");
    printf("  Total settings: %d\n", config_count);
    
    // Look for specific settings
    for (int i = 0; i < config_count; i++) {
        if (strcmp(config[i].key, "server_port") == 0) {
            printf("  Server will run on port %s\n", config[i].value);
        } else if (strcmp(config[i].key, "debug_mode") == 0) {
            printf("  Debug mode: %s\n", config[i].value);
        } else if (strcmp(config[i].key, "max_connections") == 0) {
            printf("  Maximum connections: %s\n", config[i].value);
        }
    }
    
    // Validate configuration
    printf("\nConfiguration validation:\n");
    int port_found = 0, db_host_found = 0;
    
    for (int i = 0; i < config_count; i++) {
        if (strcmp(config[i].key, "server_port") == 0) {
            port_found = 1;
            int port = atoi(config[i].value);
            if (port < 1024 || port > 65535) {
                printf("  WARNING: Invalid port number %d\n", port);
            }
        } else if (strcmp(config[i].key, "database_host") == 0) {
            db_host_found = 1;
        }
    }
    
    if (!port_found) printf("  ERROR: server_port not configured\n");
    if (!db_host_found) printf("  ERROR: database_host not configured\n");
    if (port_found && db_host_found) printf("  Configuration appears valid\n");
    
    printf("\n");
}

void demonstrate_text_statistics(void) {
    printf("=== Text File Statistics ===\n");
    
    FILE* file = fopen("sample_text.txt", "r");
    if (file == NULL) {
        perror("Failed to open text file");
        return;
    }
    
    int char_count = 0;
    int word_count = 0;
    int line_count = 0;
    int letter_freq[26] = {0};  // Frequency of each letter
    int in_word = 0;
    
    printf("Analyzing text file character by character:\n");
    
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        char_count++;
        
        if (ch == '\n') {
            line_count++;
            if (in_word) {
                word_count++;
                in_word = 0;
            }
        } else if (isspace(ch)) {
            if (in_word) {
                word_count++;
                in_word = 0;
            }
        } else {
            in_word = 1;
            
            // Count letter frequency
            if (isalpha(ch)) {
                int index = tolower(ch) - 'a';
                if (index >= 0 && index < 26) {
                    letter_freq[index]++;
                }
            }
        }
    }
    
    // Count last word if file doesn't end with whitespace
    if (in_word) {
        word_count++;
    }
    
    fclose(file);
    
    printf("\nText Statistics:\n");
    printf("  Characters: %d\n", char_count);
    printf("  Words: %d\n", word_count);
    printf("  Lines: %d\n", line_count);
    printf("  Average words per line: %.1f\n", 
           line_count > 0 ? (double)word_count / line_count : 0.0);
    printf("  Average characters per word: %.1f\n",
           word_count > 0 ? (double)char_count / word_count : 0.0);
    
    // Show letter frequency
    printf("\nLetter frequency (top 10):\n");
    
    // Create array of letter-frequency pairs for sorting
    struct {
        char letter;
        int frequency;
    } freq_pairs[26];
    
    for (int i = 0; i < 26; i++) {
        freq_pairs[i].letter = 'a' + i;
        freq_pairs[i].frequency = letter_freq[i];
    }
    
    // Simple bubble sort by frequency (descending)
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25 - i; j++) {
            if (freq_pairs[j].frequency < freq_pairs[j + 1].frequency) {
                struct { char letter; int frequency; } temp = freq_pairs[j];
                freq_pairs[j] = freq_pairs[j + 1];
                freq_pairs[j + 1] = temp;
            }
        }
    }
    
    // Show top 10
    for (int i = 0; i < 10 && freq_pairs[i].frequency > 0; i++) {
        printf("  %c: %d occurrences\n", freq_pairs[i].letter, freq_pairs[i].frequency);
    }
    printf("\n");
}

// Helper function implementations
char* trim_whitespace(char* str) {
    // Trim leading whitespace
    while (isspace(*str)) str++;
    
    // Trim trailing whitespace
    char* end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) end--;
    *(end + 1) = '\0';
    
    return str;
}

int parse_csv_line(char* line, Person* person) {
    char* token;
    int field = 0;
    
    // Make a copy since strtok modifies the string
    char line_copy[256];
    strncpy(line_copy, line, sizeof(line_copy) - 1);
    line_copy[sizeof(line_copy) - 1] = '\0';
    
    token = strtok(line_copy, ",");
    while (token != NULL && field < 5) {
        // Remove quotes if present
        if (token[0] == '"' && token[strlen(token) - 1] == '"') {
            token[strlen(token) - 1] = '\0';
            token++;
        }
        
        switch (field) {
            case 0: person->id = atoi(token); break;
            case 1: strncpy(person->name, token, sizeof(person->name) - 1); break;
            case 2: strncpy(person->email, token, sizeof(person->email) - 1); break;
            case 3: person->age = atoi(token); break;
            case 4: person->salary = atof(token); break;
        }
        
        token = strtok(NULL, ",");
        field++;
    }
    
    return field == 5;  // Success if all 5 fields parsed
}

int parse_log_line(char* line, LogEntry* entry) {
    // Expected format: "YYYY-MM-DD HH:MM:SS LEVEL COMPONENT MESSAGE"
    char* token;
    int field = 0;
    
    char line_copy[512];
    strncpy(line_copy, line, sizeof(line_copy) - 1);
    line_copy[sizeof(line_copy) - 1] = '\0';
    
    // Parse timestamp (date and time)
    token = strtok(line_copy, " ");
    if (token == NULL) return 0;
    strncpy(entry->timestamp, token, sizeof(entry->timestamp) - 1);
    
    token = strtok(NULL, " ");
    if (token == NULL) return 0;
    strncat(entry->timestamp, " ", sizeof(entry->timestamp) - strlen(entry->timestamp) - 1);
    strncat(entry->timestamp, token, sizeof(entry->timestamp) - strlen(entry->timestamp) - 1);
    
    // Parse level
    token = strtok(NULL, " ");
    if (token == NULL) return 0;
    strncpy(entry->level, token, sizeof(entry->level) - 1);
    
    // Parse component
    token = strtok(NULL, " ");
    if (token == NULL) return 0;
    strncpy(entry->component, token, sizeof(entry->component) - 1);
    
    // Parse message (rest of line)
    token = strtok(NULL, "");
    if (token == NULL) return 0;
    strncpy(entry->message, token, sizeof(entry->message) - 1);
    
    return 1;
}

int parse_config_line(char* line, ConfigEntry* entry) {
    char* equals = strchr(line, '=');
    if (equals == NULL) return 0;
    
    // Split at equals sign
    *equals = '\0';
    char* key = trim_whitespace(line);
    char* value = trim_whitespace(equals + 1);
    
    if (strlen(key) == 0 || strlen(value) == 0) return 0;
    
    strncpy(entry->key, key, sizeof(entry->key) - 1);
    strncpy(entry->value, value, sizeof(entry->value) - 1);
    entry->key[sizeof(entry->key) - 1] = '\0';
    entry->value[sizeof(entry->value) - 1] = '\0';
    
    return 1;
}

int main(void) {
    printf("File Processing - Text Processing, Parsing, and Data Extraction\n");
    printf("==============================================================\n");
    
    create_sample_files();
    demonstrate_csv_processing();
    demonstrate_log_file_analysis();
    demonstrate_config_file_parsing();
    demonstrate_text_statistics();
    
    printf("=== Key Implementation Details ===\n");
    printf("1. Manual string parsing gives complete control over format\n");
    printf("2. strtok() modifies original string - use copies for parsing\n");
    printf("3. Always validate parsed data and handle edge cases\n");
    printf("4. Character-by-character processing enables detailed analysis\n");
    printf("5. Buffer management is critical for large file processing\n");
    printf("6. Error handling prevents crashes from malformed data\n");
    
    // Cleanup test files
    remove("employees.csv");
    remove("application.log");
    remove("app.conf");
    remove("sample_text.txt");
    printf("\nTest files cleaned up\n");
    
    return 0;
}