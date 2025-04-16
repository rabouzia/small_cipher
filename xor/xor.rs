fn xoring(msg: &str, key: &str)-> String {
    let mut full_key = key.repeat(msg.len() / key.len());
    full_key.push_str(&key[..msg.len() % key.len()]);

    let encrypted: String = msg.bytes().zip(full_key.bytes())
    .map(|(m, k)| (m ^ k) as char).collect();
    return  encrypted;
}

fn main (){

    let str= "Hello World";
    let xor= "xor";
    let encrypt = xoring(str, xor);
    println!(" key is [{}]", encrypt);
    let decrypt = xoring(&encrypt, xor);
    println!(" key is [{}]", decrypt);

}