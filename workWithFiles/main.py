def process_roles(roles_list, text_lines):
    lines_by_role = {}

    for line_num, line_text in enumerate(text_lines, 1):
        if ":" not in line_text:
            continue
        role_name, message = line_text.split(":", 1)
        message = message.strip()
        if role_name not in lines_by_role:
            lines_by_role[role_name] = []
        lines_by_role[role_name].append((line_num, message))

    output_lines = []
    for i, role in enumerate(roles_list):
        output_lines.append(role + ":")
        if role in lines_by_role:
            for num, text in lines_by_role[role]:
                output_lines.append(f"{num}) {text}")
        if i < len(roles_list) - 1:
            output_lines.append("")

    return "\n".join(output_lines)


def main():
    with open("input.txt", "r", encoding="utf-8") as file:
        content = file.readlines()

    content = [line.strip() for line in content if line.strip()]
    
    roles_section = None
    text_section = None
    
    for index, line in enumerate(content):
        if line == "roles:":
            roles_section = index + 1
        elif line == "textLines:":
            text_section = index + 1
            break

    roles = []
    if roles_section is not None and text_section is not None:
        for j in range(roles_section, text_section - 1):
            roles.append(content[j])

    text_data = []
    if text_section is not None:
        text_data = content[text_section:]

    result = process_roles(roles, text_data)

    with open("output.txt", "w", encoding="utf-8") as out_file:
        out_file.write(result)

    print("Результат записан в output.txt")


if __name__ == "__main__":
    main()